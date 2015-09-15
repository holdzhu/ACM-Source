#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char s[201];
double ans[201];
int sum[400];
int dp[201][201];

int main()
{
	// freopen("blind.in", "r", stdin);
	// freopen("blind.out", "w", stdout);
	scanf("%s", s);
	int n = strlen(s);
	for (int l = 1; l <= n * 2; ++l)
	{
		memset(sum, 0, sizeof sum);
		int d = n / __gcd(n, l);
		for (int i = 0; i < d * l; ++i)
		{
			sum[i % l] += s[i % n] - '0';
		}
		dp[0][0] = 0;
		for (int i = 1; i <= l; ++i)
		{
			for (int j = 0; j <= i; ++j)
			{
				if (j <= n && i - j <= n)
				{
					dp[j][i - j] = 0;
					if (j)
					{
						dp[j][i - j] = max(dp[j][i - j], dp[j - 1][i - j] + d - sum[i - 1]);
					}
					if (i - j)
					{
						dp[j][i - j] = max(dp[j][i - j], dp[j][i - j - 1] + sum[i - 1]);
					}
				}
			}
		}
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 0; j <= l; ++j)
			{
				if (j <= i && l - j <= i)
				{
					ans[i] = max(ans[i], dp[j][l - j] / (d * l * 1.0));
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		printf("%.10f\n", ans[i]);
	}
	return 0;
}
