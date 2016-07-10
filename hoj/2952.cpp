#include <cstdio>

const int inf = 1e9;

int sum[1001];
int dp[1000][1000];
int K[1000][1000];

int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		for (int i = 0; i < n; ++i)
			scanf("%d", &dp[i][i]), K[i][i] = i, sum[i + 1] = sum[i] + dp[i][i];
		for (int i = 1; i < n; ++i)
			for (int l = 0; l < n; ++l)
			{
				int r = l + i;
				if (r >= n)
					r -= n;
				dp[l][r] = inf;
				for (int k = K[l][(r + n - 1) % n]; ; k = (k + 1) % n)
				{
					int tmp = dp[l][k] + dp[(k + 1) % n][r] + sum[r + 1] - sum[l];
					if (r < l)
						tmp += sum[n];
					if (tmp < dp[l][r])
					{
						dp[l][r] = tmp;
						K[l][r] = k;
					}
					if (k == K[(l + 1) % n][r])
						break;
				}
			}
		int ans = inf;
		for (int i = 0; i < n; ++i)
			if (ans > dp[(i + 1) % n][i])
				ans = dp[(i + 1) % n][i];
		printf("%d\n", ans - sum[n]);
	}
	return 0;
}
