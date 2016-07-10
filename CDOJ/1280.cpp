#include <cstdio>

const int mod = 10007;

int m, n, t;
int C[11][11];
int dp[11];
int tmp[11];

void solve(int n)
{
	if (!n)
	{
		for (int i = 1; i <= t; ++i)
			dp[i] = 0;
		dp[0] = 1;
	}
	else if (n & 1)
	{
		solve(n ^ 1);
		for (int i = 0; i <= t; ++i)
		{
			tmp[i] = dp[i] * (m - t) % mod;
			if (i)
				tmp[i] = (tmp[i] + dp[i - 1] * i) % mod;
			if (i < t)
				tmp[i] = (tmp[i] + dp[i + 1] * (t - i)) % mod;
		}
		for (int i = 0; i <= t; ++i)
			dp[i] = tmp[i];
	}
	else
	{
		solve(n >> 1);
		for (int i = 0; i <= t; ++i)
			tmp[i] = 0;
		for (int i = 0; i <= t; ++i)
			for (int j = i; j <= t; ++j)
				for (int k = i; j + k - i <= t; ++k)
					tmp[j + k - i - i] = (tmp[j + k - i - i] + dp[j] * dp[k] % mod * C[j + k - i - i][j - i] % mod * C[t - (j + k - i - i)][i] % mod) % mod;
		for (int i = 0; i <= t; ++i)
			dp[i] = tmp[i];
	}
}

int main()
{
	scanf("%d %d %d", &m, &n, &t);
	for (int i = 0; i <= m; ++i)
	{
		C[i][0] = 1;
		for (int j = 1; j < i; ++j)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
		C[i][i] = 1;
	}
	solve(n);
	printf("%d\n", dp[0]);
	return 0;
}
