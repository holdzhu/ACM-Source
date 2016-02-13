#include <cstdio>

const int mod = 98765431;
int G[15][15];
long long dp[1 << 15][15];
int msk[15];
bool sp[15];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				scanf("%d", &G[i][j]);
			}
		}
		for (int i = 0; i < n; ++i)
			sp[i] = false;
		int m;
		scanf("%d", &m);
		int last = -1;
		int first = -1;
		bool flag = true;
		for (int i = 0; i < m; ++i)
		{
			int u;
			scanf("%d", &u);
			if (sp[u])
				flag = false;
			sp[u] = true;
			if (last == -1)
				msk[u] = 0;
			else
				msk[u] = msk[last] | (1 << last);
			if (i == 0)
				first = u;
			last = u;
		}
		if (!flag)
		{
			puts("0");
			continue;
		}
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < (1 << n); ++j)
				dp[j][i] = 0;
		dp[1 << first][first] = 1;
		for (int j = 0; j < (1 << n); ++j)
		{
			for (int i = 0; i < n; ++i)
			{
				if (j >> i & 1)
				{
					for (int k = 0; k < n; ++k)
					{
						if (!(j >> k & 1) && G[i][k] && (!sp[k] || (sp[k] && (j & msk[k]) == msk[k])))
						{
							dp[j | (1 << k)][k] = (dp[j | (1 << k)][k] + dp[j][i]) % mod;
						}
					}
				}
			}
		}
		long long ans = 0;
		for (int i = 0; i < n; ++i)
			if (G[i][first])
				ans = (ans + dp[(1 << n) - 1][i]) % mod;
		printf("%lld\n", ans);
	}
	return 0;
}
