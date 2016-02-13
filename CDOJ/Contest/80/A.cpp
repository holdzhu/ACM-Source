#include <cstdio>

const int mod = 1e9 + 7;
long long dp[1004][1004];
long long C[1004][1004];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	dp[0][0] = 1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			dp[i][j + 1] = (dp[i][j + 1] + dp[i][j] * (i - j)) % mod;
			dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % mod;
			dp[i + 2][j + 1] = (dp[i + 2][j + 1] + dp[i][j]) % mod;
		}
	}
	C[0][0] = 1;
	for (int i = 1; i < n; ++i)
	{
		C[i][0] = 1;
		for (int j = 1; j <= i; ++j)
		{
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
		}
	}
	printf("%lld\n", dp[m - 1][m - 1] * dp[n - m][n - m] % mod * C[n - 1][m - 1] % mod);
	return 0;
}
