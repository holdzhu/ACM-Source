#include <cstdio>
#include <cstring>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, k;
		scanf("%d %d", &n, &k);
		int f[n][n];
		memset(f, 0, sizeof(f));
		for (int i = 0; i < (1 << n); ++i)
		{
			bool b[n];
			int num = 0;
			for (int j = 0; j < n; ++j)
			{
				b[j] = (i >> j) & 1;
				if (b[j])
				{
					num++;
				}
			}
			int dp[n][n];
			memset(dp, 0, sizeof(dp));
			int s[n][n];
			memset(s, 0, sizeof(s));
			for (int j = 0; j < n; ++j)
			{
				if (b[j])
				{
					dp[j][0] = 1;
					for (int k = 0; k < 8; ++k)
					{
						dp[j][k + 1] += j > 1 ? s[j - 2][k] : 0;
						s[j][k] = (j > 0 ? s[j - 1][k] : 0) + dp[j][k];
					}
				}
			}
			for (int j = 0; j < n; ++j)
			{
				for (int k = 0; k < n; ++k)
				{
					f[num][k] += dp[j][k];
				}
			}
		}
		for (int i = 0; i < n; ++i)
		{
			
		}
	}
	return 0;
}
