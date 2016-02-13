#include <cstdio>
#include <algorithm>

int dp[1003][1003];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			dp[i][j] = -1e9;
		}
	}
	dp[0][0] = 0;
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int t = 0;
			scanf("%d", &t);
			dp[i][j] += t;
			if (dp[i][j] < 0)
			{
				dp[i][j] = -1e9;
			}
			ans = std::max(ans, dp[i][j]);
			dp[i + 1][j] = std::max(dp[i + 1][j], dp[i][j]);
			dp[i + 1][j + 2] = std::max(dp[i + 1][j + 2], dp[i][j]);
			dp[i + 2][j + 1] = std::max(dp[i + 2][j + 1], dp[i][j]);
			dp[i][j + 1] = std::max(dp[i][j + 1], dp[i][j]);
		}
	}
	printf("%d\n", ans);
	return 0;
}
