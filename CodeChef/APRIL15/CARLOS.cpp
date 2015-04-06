#include <cstdio>
#include <cstring>

const int INF = 100000000;

int dp[200001][200];
int p[200];
bool d[200][200];

int find(int x)
{
	return x == p[x] ? x : p[x] = find(p[x]);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		memset(dp, -1, sizeof dp);
		memset(d, 0, sizeof d);
		int M, K, N;
		scanf("%d %d %d", &M, &K, &N);
		for (int i = 0; i < M; ++i)
		{
			p[i] = i;
		}
		int x, y;
		while (K--)
		{
			scanf("%d %d", &x, &y);
			p[find(x - 1)] = find(y - 1);
		}
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (find(i) == find(j))
				{
					d[i][j] = true;
				}
			}
		}
		for (int i = 0; i < M; ++i)
		{
			dp[0][i] = 0;
		}
		int t;
		for (int i = 1; i <= N; ++i)
		{
			scanf("%d", &t);
			int m = INF;
			for (int j = 0; j < M; ++j)
			{
				if (dp[i - 1][j] != -1 && dp[i - 1][j] < m)
				{
					m = dp[i - 1][j];
				}
				if (m != -1)
				{
					if (j == t - 1)
					{
						dp[i][j] = m;
					}
					else if (d[t - 1][j])
					{
						dp[i][j] = m + 1;
					}
				}
			}
		}
		int ans = INF;
		for (int i = 0; i < M; ++i)
		{
			if (dp[N][i] != -1 && dp[N][i] < ans)
			{
				ans = dp[N][i];
			}
		}
		if (ans == INF)
		{
			printf("-1\n");
		}
		else
		{
			printf("%d\n", ans);
		}
	}
	return 0;
}
