#include <cstdio>
#include <cstring>

int a[700];
int dp[2][10001];

int gcd(int a, int b)
{
	return !b ? a : gcd(b, a % b);
}

int main()
{
	int n;
	scanf("%d", &n);
	int G = 0;
	int top = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
		G = gcd(a[i], G);
		if (a[i] > top)
		{
			top = a[i];
		}
	}
	int cur = 0;
	for (int i = 1; i <= top; ++i)
	{
		dp[0][i] = n + 1;
	}
	for (int i = 0; i < n; ++i)
	{
		cur = !cur;
		for (int j = 1; j <= top; ++j)
		{
			dp[cur][j] = dp[!cur][j];
		}
		dp[cur][a[i]] = 1;
		for (int j = 1; j <= top; ++j)
		{
			if (dp[cur][gcd(j, a[i])] > dp[!cur][j] + 1)
			{
				dp[cur][gcd(j, a[i])] = dp[!cur][j] + 1;
			}
		}
	}
	printf("%d\n", n - dp[cur][G]);
	return 0;
}
