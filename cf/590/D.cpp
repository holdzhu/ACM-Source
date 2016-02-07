#include <cstdio>
#include <algorithm>

using namespace std;

int dp[80][12000];
int q[150];

int main()
{
	int n, k, s;
	scanf("%d %d %d", &n, &k, &s);
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &q[i]);
		sum += q[i];
	}
	if (k == n)
	{
		printf("%d\n", sum);
	}
	else if (k < n / 2)
	{
		s += k * (k + 1) / 2;
		s = min(s, n * (n + 1) / 2);
		for (int i = 0; i <= s; ++i)
		{
			for (int j = 0; j <= k; ++j)
			{
				dp[j][i] = j == 0 ? 0 : 1e9;
			}
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = min(i + 1, k); j > 0; --j)
			{
				for (int v = s; v >= i + 1; --v)
				{
					dp[j][v] = min(dp[j][v], dp[j - 1][v - i - 1] + q[i]);
				}
			}
		}
		printf("%d\n", dp[k][s]);
	}
	else
	{
		k = n - k;
		s += k * (k + 1) / 2;
		s = min(s, n * (n + 1) / 2);
		for (int i = 0; i <= s; ++i)
		{
			for (int j = 0; j <= k; ++j)
			{
				dp[j][i] = j == 0 ? 0 : -1e9;
			}
		}
		for (int i = n - 1; i >= 0; --i)
		{
			for (int j = min(n - i, k); j > 0; --j)
			{
				for (int v = s; v >= n - i; --v)
				{
					dp[j][v] = max(dp[j][v], dp[j - 1][v - (n - i)] + q[i]);
				}
			}
		}
		printf("%d\n", sum - dp[k][s]);
	}
	return 0;
}