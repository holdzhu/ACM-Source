#include <cstdio>
#include <cstring>

inline int min(int a, int b)
{
	return a < b ? a : b;
}

long long dp[2][501][501];

int main()
{
	int n, m, b;
	long long mod;
	memset(dp, 0, sizeof dp);
	scanf("%d %d %d %I64d", &n, &m, &b, &mod);
	dp[0][0][0] = 1;
	int cur = 1;
	for (int i = 0; i < n; ++i)
	{
		int t;
		scanf("%d", &t);
		for (int C = 0; C <= b; ++C)
		{
			for (int M = 0; M <= m; ++M)
			{
				dp[cur][M][C] = dp[1 - cur][M][C];
				if (M > 0 && C >= t)
				{
					dp[cur][M][C] += dp[cur][M - 1][C - t];
					while (dp[cur][M][C] >= mod)
					{
						dp[cur][M][C] -= mod;
					}
				}
			}
		}
		cur = 1 - cur;
	}
	long long ans = 0;
	for (int i = 0; i <= b; ++i)
	{
		ans += dp[1 - cur][m][i];
		while (ans >= mod)
		{
			ans -= mod;
		}
	}
	printf("%I64d\n", ans);
	return 0;
}
