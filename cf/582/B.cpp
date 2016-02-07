#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1000000;
int dp[maxn + maxn + 1];
int a[100];
int c[301];
int left[301];

int main()
{
	int n, T;
	scanf("%d %d", &n, &T);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
		c[a[i]]++;
	}
	int ans = 0;
	for (int i = 0; i <= maxn * 2; ++i)
	{
		dp[i] = 1e9;
	}
	if (n * T <= maxn * 2)
	{
		for (int i = 0; i < n * T; ++i)
		{
			int pos = lower_bound(dp, dp + n * T + 1, a[i % n] + 1) - dp;
			ans = max(ans, pos + 1);
			dp[pos] = a[i % n];
		}
	}
	else
	{
		int maxT = maxn / n;
		for (int i = 0; i < n * maxT; ++i)
		{
			int pos = lower_bound(dp, dp + n * maxT + 1, a[i % n] + 1) - dp;
			left[a[i % n]] = max(left[a[i % n]], pos + 1);
			dp[pos] = a[i % n];
		}
		for (int i = 0; i <= maxn; ++i)
		{
			dp[i] = 1e9;
		}
		for (int i = 0; i < n * maxT; ++i)
		{
			int pos = lower_bound(dp, dp + n * maxT + 1, -a[n - 1 - i % n] + 1) - dp;
			ans = max(ans, left[a[n - 1 - i % n]] + pos + 1 + (T - maxT - maxT) * c[a[n - 1 - i % n]]);
			dp[pos] = -a[n - 1 - i % n];
		}
	}
	printf("%d\n", ans);
	return 0;
}
