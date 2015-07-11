#include <cstdio>
#include <algorithm>

using namespace std;

int w[200002];
int h[200002];
int dp[200002];
int left[200002];
int right[200002];
long long sw[200002];
int top;

bool cmp(const int &a, const int &b)
{
	return h[a] < h[b];
}

int main()
{
	int n;
	scanf("%d", &n);
	h[0] = 0;
	h[n + 1] = 0;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d %d", &w[i], &h[i]);
	}
	top = 1;
	dp[0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		top = lower_bound(dp, dp + top, i, cmp) - dp;
		left[i] = dp[top - 1];
		dp[top++] = i;
	}
	top = 1;
	dp[0] = n + 1;
	for (int i = n; i > 0; --i)
	{
		top = lower_bound(dp, dp + top, i, cmp) - dp;
		right[i] = dp[top - 1];
		dp[top++] = i;
	}
	sw[0] = 0;
	for (int i = 0; i < n; ++i)
	{
		sw[i + 1] = sw[i] + w[i + 1];
	}
	long long ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		ans = max(ans, (sw[right[i] - 1] - sw[left[i]]) * h[i]);
	}
	printf("%lld\n", ans);
	return 0;
}
