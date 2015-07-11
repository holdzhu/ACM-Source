#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

long long dp[100][100];
long long sum[101];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		memset(dp, -1, sizeof dp);
		sum[0] = 0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%lld", &sum[i + 1]);
			sum[i + 1] += sum[i];
			dp[i][i] = 0;
		}
		for (int i = 1; i < n; ++i)
		{
			for (int j = 0; j + i < n; ++j)
			{
				for (int k = 0; k < i; ++k)
				{
					if (dp[j][j + i] == -1 || dp[j][j + i] > dp[j][j + k] + dp[j + k + 1][j + i] + ((sum[j + k + 1] - sum[j] + 100) % 100) * ((sum[j + i + 1] - sum[j + k + 1] + 100) % 100))
					{
						dp[j][j + i] = dp[j][j + k] + dp[j + k + 1][j + i] + ((sum[j + k + 1] - sum[j] + 100) % 100) * ((sum[j + i + 1] - sum[j + k + 1] + 100) % 100);
					}
				}
			}
		}
		printf("%lld\n", dp[0][n - 1]);
	}
	return 0;
}
