#include <cstdio>
#include <cstring>
#include <deque>
#include <algorithm>

using namespace std;

long long dp[2][1001];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N, K, A;
		scanf("%d %d %d", &N, &K, &A);
		bool cur = 0;
		memset(dp, 0, sizeof dp);
		for (int i = 0; i < N; ++i)
		{
			int h;
			scanf("%d", &h);
			cur = !cur;
			deque<pair<int, long long> > q;
			for (int j = 0; j <= 1000; ++j)
			{
				while (!q.empty() && q.back().first < j - K)
				{
					q.pop_back();
				}
				while (!q.empty() && q.front().second >= dp[!cur][j] - A * j)
				{
					q.pop_front();
				}
				q.push_front(make_pair(j, dp[!cur][j] - A * j));
				dp[cur][j] = q.back().second + A * j + (j - h) * (j - h);
			}
			q.clear();
			for (int j = 1000; j >= 0; --j)
			{
				while (!q.empty() && q.back().first > j + K)
				{
					q.pop_back();
				}
				while (!q.empty() && q.front().second >= dp[!cur][j] + A * j)
				{
					q.pop_front();
				}
				q.push_front(make_pair(j, dp[!cur][j] + A * j));
				dp[cur][j] = min(dp[cur][j], q.back().second - A * j + (j - h) * (j - h));
			}
		}
		long long ans = 10000000000000000LL;
		for (int i = 0; i <= 1000; ++i)
		{
			ans = min(ans, dp[cur][i]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
