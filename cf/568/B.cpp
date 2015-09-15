#include <cstdio>
#include <cstring>

const int mod = 1000000007;
long long dp[4001][4001];

int main()
{
	int n;
	scanf("%d", &n);
	memset(dp, 0, sizeof dp);
	dp[0][0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			dp[i][j] = (dp[i - 1][j] * j + dp[i - 1][j - 1]) % mod;
		}
	}
	long long ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		ans += dp[n][i] * i % mod;
		ans %= mod;
	}
	printf("%I64d\n", ans);
	return 0;
}
