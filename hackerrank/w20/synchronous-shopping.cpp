#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int inf = 1e9;

vector<pair<int, int> > G[1001];
int msk[1001];
int dp[1001][1 << 10];

int main()
{
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 1; i <= N; ++i)
	{
		int T;
		scanf("%d", &T);
		while (T--)
		{
			int A;
			scanf("%d", &A);
			msk[i] |= 1 << --A;
		}
	}
	while (M--)
	{
		int X, Y, Z;
		scanf("%d %d %d", &X, &Y, &Z);
		G[X].emplace_back(Y, Z);
		G[Y].emplace_back(X, Z);
	}
	for (int i = 1; i <= N; ++i)
		for (int j = 0; j < (1 << K); ++j)
			dp[i][j] = inf;
	dp[1][msk[1]] = 0;
	priority_queue<pair<int, pair<int, int> > > pq;
	pq.push({0, {1, msk[1]}});
	while (!pq.empty())
	{
		int u = pq.top().second.first;
		int b = pq.top().second.second;
		pq.pop();
		for (auto &p: G[u])
		{
			int v = p.first;
			int w = p.second;
			int nb = b | msk[v];
			if (dp[v][nb] > dp[u][b] + w)
				pq.push({-(dp[v][nb] = dp[u][b] + w), {v, nb}});
		}
	}
	int ans = inf;
	for (int i = 0; i < (1 << K); ++i)
		for (int j = 0; j < (1 << K); ++j)
			if ((i | j) == (1 << K) - 1)
				ans = min(ans, max(dp[N][i], dp[N][j]));
	printf("%d\n", ans);
	return 0;
}
