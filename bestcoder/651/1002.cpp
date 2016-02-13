#include <cstdio>
#include <algorithm>

using namespace std;

int a[1010][1010];
int dp[1010][1010];

int main()
{
	int n, m;
	while (scanf("%d %d", &n, &m) == 2)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				scanf("%d", &a[i][j]);
				dp[i][j] = 2e9;
			}
		}
		dp[0][1] = a[0][0] * a[0][1];
		dp[1][0] = a[0][0] * a[1][0];
		for (int i = 0; i < n; ++i)
		{
			for (int j = ~i & 1; j < m; j += 2)
			{
				dp[i][j + 2] = min(dp[i][j + 2], dp[i][j] + a[i][j + 1] * a[i][j + 2]);
				dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + a[i][j + 1] * a[i + 1][j + 1]);
				dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + a[i + 1][j] * a[i + 1][j + 1]);
				dp[i + 2][j] = min(dp[i + 2][j], dp[i][j] + a[i + 1][j] * a[i + 2][j]);
			}
		}
		printf("%d\n", dp[n - 1][m - 1]);
	}
	return 0;
}
