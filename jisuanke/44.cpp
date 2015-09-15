#include <cstdio>

char s[250][251];
int dp[250][250];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", s[i]);
		for (int j = 0; j < n; ++j)
		{
			dp[i][j] = s[i][j] == '1';
		}
	}
	for (int k = 2; k <= n; ++k)
	{
		int cnt = 0;
		for (int i = n - 1; i >= 0; --i)
		{
			for (int j = n - 1; j >= 0; --j)
			{
				dp[i][j] = i >= k - 1 && j >= k - 1 && dp[i - 1][j - 1] && dp[i][j - 1] && dp[i - 1][j] && dp[i][j];
				cnt += dp[i][j];
			}
		}
		if (cnt)
		{
			printf("%d %d\n", k, cnt);
		}
		else
		{
			break;
		}
	}
	return 0;
}
