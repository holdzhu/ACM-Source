#include <cstdio>
#include <algorithm>

const long long mod = 1000000007;

long long f[2002];
long long dp[1001][2001];

int main()
{
	int T;
	scanf("%d", &T);
	dp[0][0] = 1;
	for (int i = 0; i <= 2001; ++i)
	{
		f[i] = i * (i + 1);
	}
	while (T--)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		int maxj = std::min((n + 1) >> 1, m);
		for (int i = 1; i <= (n + 1) >> 1; ++i)
		{
			int t = std::min(std::min(i * 2, n + 1 - i * 2), maxj);
			for (int j = 0; j <= t; j += 2)
			{
				dp[i][j] = ((j > 0 ? f[m - j + 1] * dp[i - 1][j - 2] : 0) + 
							(2 * j * (m - j) + m) * dp[i - 1][j] + 
							(j < maxj - 1 ? f[j + 1] * dp[i - 1][j + 2] : 0)) % mod;
			}
		}
		long long ms = 1;
		long long ans = 0;
		for (int i = n; i >= 1; --i)
		{
			ans += (n + 1 - i) * ms % mod * dp[(i + 1) >> 1][0] % mod;
			ans %= mod;
			ms = ms * m % mod;
		}
		printf("%I64d\n", ans);
	}
	return 0;
}
