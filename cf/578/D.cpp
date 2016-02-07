#include <cstdio>

char s[100010];
long long dp[100010][4];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	scanf("%s", s);
	dp[0][0] = 1;
	for (int i = 0; i < n; ++i)
	{
		for (char c = 'a'; c < 'a' + m; ++c)
		{
			if (c == s[i])
			{
				dp[i + 1][0] += dp[i][0];
				dp[i + 1][3] += dp[i][1];
				dp[i + 1][3] += dp[i][2];
			}
			else if (c == s[i + 1])
			{
				dp[i + 1][2] += dp[i][0];
			}
			else if (i && c == s[i - 1])
			{
				dp[i + 1][1] += dp[i][0];
			}
		}
	}
	printf("%I64d\n", dp[n][1]);
	return 0;
}
