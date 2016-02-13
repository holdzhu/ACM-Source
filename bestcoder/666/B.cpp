#include <cstdio>

bool dp[10001];
int w[20];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		int sum = 0;
		for (int i = 0; i < n; ++i)
			scanf("%d", &w[i]), sum += w[i];
		for (int i = 0; i <= sum * 2; ++i)
			dp[i] = 0;
		dp[0] = 1;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < 2; ++j)
			{
				for (int k = sum * 2; k >= w[i]; --k)
				{
					dp[k] |= dp[k - w[i]];
				}
			}
		}
		int m;
		scanf("%d", &m);
		while (m--)
		{
			int k;
			scanf("%d", &k);
			int id = k + sum;
			puts(id >= 0 && id <= sum * 2 && dp[id] ? "YES" : "NO");
		}
	}
	return 0;
}
