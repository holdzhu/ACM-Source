#include <cstdio>

int dp[20][20];

int main()
{
	int n, r;
	scanf("%d %d", &n, &r);
	dp[0][0] = r;
	int ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j <= i; ++j)
			if (dp[i][j] >= (1 << i))
			{
				++ans;
				dp[i + 1][j] += dp[i][j] - (1 << i);
				dp[i + 1][j + 1] += dp[i][j] - (1 << i);
			}
	printf("%d\n", ans);
	return 0;
}
