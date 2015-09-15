#include <cstdio>
#include <algorithm>

const long long mod = 1000000007;

long long dp[2001][2001];

int main()
{
	int T;
	scanf("%d", &T);
	dp[0][0] = 1;
	while (T--)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		int maxj = std::min((n + 1) >> 1, m);
		for (int i = 1; i <= n; ++i)
		{
			int t = std::min(std::min(i, n + 1 - i), maxj);
			for (int j = i & 1; j <= t; j += 2)
			{
				dp[i][j] = ((j > 0 ? ((m - j + 1) * dp[i - 1][j - 1]) : 0) + (j < maxj ? ((j + 1) * dp[i - 1][j + 1]) : 0)) % mod;
			}
		}
		long long ms = 1;
		long long ans = 0;
		for (int i = n; i >= 1; --i)
		{
			ans += (n + 1 - i) * ms % mod * dp[i][i & 1] % mod;
			ans %= mod;
			ms = ms * m % mod;
		}
		printf("%I64d\n", ans);
	}
	return 0;
}
