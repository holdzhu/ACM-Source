#include <cstdio>

long long dp[60];

int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		long long ans = 0;
		for (int i = 1; i <= n; ++i)
		{
			dp[i] = 1;
			for (int j = 1; j + 3 <= i; ++j)
			{
				dp[i] += dp[j];
			}
			ans += dp[i];
		}
		printf("%I64d\n", ans);
	}
	return 0;
}
