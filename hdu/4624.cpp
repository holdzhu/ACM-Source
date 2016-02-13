#include <cstdio>
#include <cstring>

const int maxsum = 50 * 51 / 2;
long long dp[51][maxsum + 1];
long long ans[maxsum + 1];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		memset(dp, 0, sizeof dp);
		memset(ans, 0, sizeof ans);
		int sum = n * (n + 1) / 2;
		dp[0][sum] = -1;
		for (int i = 0; i <= n; ++i)
		{
			for (int j = 0; j <= sum; ++j)
			{	
				ans[j] += dp[i][j];
				for (int k = i + 1; k <= n; ++k)
				{
					if (j >= n - i + (k - i - 1) * (n - k))
					{
						dp[k][j - n + i - (k - i - 1) * (n - k)] -= dp[i][j];
					}
				}
			}
		}
		long double out = 0;
		for (int i = 0; i < sum; ++i)
		{
			out += ans[i] * sum / (long double)(sum - i);
		}
		printf("%.15f\n", (double)out);
	}
	return 0;
}
