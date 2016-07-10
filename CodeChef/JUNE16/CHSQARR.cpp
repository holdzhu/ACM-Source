#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int A[1000][1000];
int sum[1001][1001];
int maxr[1000][1000];

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			scanf("%d", &A[i][j]);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + A[i][j];
	int Q;
	scanf("%d", &Q);
	while (Q--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		for (int i = 0; i < N; ++i)
		{
			deque<pair<int, int> > q;
			for (int j = 0; j < b; ++j)
			{
				while (q.size() && q.back().second <= A[i][j])
					q.pop_back();
				q.push_back({j, A[i][j]});
			}
			maxr[i][0] = q.front().second;
			for (int j = b; j < M; ++j)
			{
				if (q.front().first <= j - b)
					q.pop_front();
				while (q.size() && q.back().second <= A[i][j])
					q.pop_back();
				q.push_back({j, A[i][j]});
				maxr[i][j - b + 1] = q.front().second;
			}
		}
		int ans = 1e9;
		for (int i = 0; i < M - b + 1; ++i)
		{
			deque<pair<int, int> > q;
			for (int j = 0; j < a; ++j)
			{
				while (q.size() && q.back().second <= maxr[j][i])
					q.pop_back();
				q.push_back({j, maxr[j][i]});
			}
			ans = min(ans, a * b * q.front().second - (sum[a][i + b] - sum[a][i] - sum[0][i + b] + sum[0][i]));
			for (int j = a; j < N; ++j)
			{
				if (q.front().first <= j - a)
					q.pop_front();
				while (q.size() && q.back().second <= maxr[j][i])
					q.pop_back();
				q.push_back({j, maxr[j][i]});
				ans = min(ans, a * b * q.front().second - (sum[j + 1][i + b] - sum[j + 1][i] - sum[j - a + 1][i + b] + sum[j - a + 1][i]));
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
