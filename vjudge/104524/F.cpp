#include <cstdio>
#include <cstring>

const int mod = 1e9 + 7;
char s[5001], t[5001];
int dp[5001][5001];

int main()
{
	scanf("%s %s", s, t);
	int n = strlen(s);
	int m = strlen(t);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			if (j > 0)
				dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
			if (s[i] == t[j])
			{
				dp[i][j] = (dp[i][j] + 1) % mod;
				if (i > 0 && j > 0)
					dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
			}
		}
	int ans = 0;
	for (int i = 0; i < n; ++i)
		ans = (ans + dp[i][m - 1]) % mod;
	printf("%d\n", ans);
	return 0;
}
