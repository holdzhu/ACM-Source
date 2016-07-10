#include <cstdio>

double dp[1 << 18][18];
double p[18][18];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%lf", &p[i][j]);
	for (int i = 0; i < n; ++i)
		dp[1 << i][i] = 1;
	for (int i = 0; i < (1 << n); ++i)
		for (int j = 0; j < n; ++j)
			if (~i >> j & 1)
			{
				int m = (1 << j) | i;
				for (int k = 0; k < n; ++k)
					if (i >> k & 1)
					{
						dp[m][j] += dp[i][k] * p[j][k];
						dp[m][k] += dp[i][k] * p[k][j];
					}
			}
	double ans = dp[(1 << n) - 1][0];
	for (int i = 1; i <= n; ++i)
		printf("%.10f\n", dp[(1 << n) - 1][i - 1]);
	printf("%.10f\n", ans);
	return 0;
}
