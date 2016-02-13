#include <cstdio>
#include <algorithm>

using namespace std;

int a[100001];
long long dp[100001][3];

int f(int x)
{
	return (1890 * x + 143) % 10007;
}

int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", a + i);
		}
		dp[0][0] = dp[0][1] = dp[0][2] = 0;
		for (int i = 1; i <= n; ++i)
		{
			int g = f(a[i - 1]);
			dp[i][0] = dp[i - 1][0] + a[i - 1];
			dp[i][1] = max(dp[i - 1][1] + g, dp[i - 1][0] + g);
			dp[i][2] = max(dp[i - 1][2] + a[i - 1], dp[i - 1][1] + a[i - 1]);
		}
		printf("%I64d\n", max(dp[n][0], max(dp[n][1], dp[n][2])));
	}
	return 0;
}
