#include <cstdio>
#include <cstring>

const int mod = 1e9 + 7;

int a[2][2];

int b[50000];

int dp[50000][2][2];

int main()
{
	int n, p;
	scanf("%d %d", &n, &p);
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &b[i]);
	}
	long long ans = 0;
	for (int i = 0; i < p; ++i)
	{
		for (int j = 0; j < p; ++j)
		{
			memset(dp[0], 0, sizeof dp[0]);
			dp[0][b[0] >> i & 1][b[0] >> j & 1] = 1;
			for (int k = 1; k < n; ++k)
			{
				long long tmp[2][2] = {{0, 0}, {0, 0}};
				for (int I = 0; I < 2; ++I)
				{
					for (int J = 0; J < 2; ++J)
					{
						tmp[a[I][b[k] >> i & 1]][a[J][b[k] >> j & 1]] += dp[k - 1][I][J];
					}
				}
				tmp[b[k] >> i & 1][b[k] >> j & 1]++;
				for (int I = 0; I < 2; ++I)
				{
					for (int J = 0; J < 2; ++J)
					{
						dp[k][I][J] = (dp[k - 1][I][J] + tmp[I][J] % mod) % mod;
					}
				}
			}
			ans = (ans + ((((long long)dp[n - 1][1][1] << i) % mod) << j) % mod) % mod;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
