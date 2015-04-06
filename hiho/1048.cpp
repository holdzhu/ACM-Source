#include <cstdio>
#include <cstring>

const int pow[] = {1, 3, 9, 27, 81, 243, 729};
const int mod = 1000000007;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int maxm = pow[m];
	long long dp[2][maxm];
	int cur = 0;
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	int endline = m * (n - 1);
	for (int i = 0; i < m * n; ++i)
	{
		memset(dp[!cur], 0, sizeof dp[!cur]);
		for (int j = 0; j < maxm; ++j)
		{
			if (j % 3 == 1 || j / pow[m - 1] == 2)
			{
				dp[!cur][(j * 3) % maxm] += dp[cur][j];
				dp[!cur][(j * 3) % maxm] %= mod;
			}
			else
			{
				if (i < endline)
				{
					dp[!cur][(j * 3 + 2) % maxm] += dp[cur][j];
					dp[!cur][(j * 3 + 2) % maxm] %= mod;
				}
				if (i % m < m - 1 && j / pow[m - 2] % 3 != 2)
				{
					dp[!cur][(j * 3 + 1) % maxm] += dp[cur][j];
					dp[!cur][(j * 3 + 1) % maxm] %= mod;
				}
			}
		}
		cur = !cur;
	}
	long long ans = 0;
	for (int j = 0; j < maxm; ++j)
	{
		ans += dp[cur][j];
		ans %= mod;
	}
	printf("%lld\n", ans);
	return 0;
}
