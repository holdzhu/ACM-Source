#include <cstdio>
#include <cstring>

struct Pair
{
	long long num;
	long long count;
};

Pair dp[2][5001];
int top[2];

int main()
{
	int m, R;
	scanf("%d %d", &m, &R);
	memset(dp, 0, sizeof dp);
	memset(top, 0, sizeof top);
	int cur = 0;
	dp[cur][top[cur]++] = (Pair){R + 1, 1};
	while (m--)
	{
		int mod;
		scanf("%d", &mod);
		cur = !cur;
		top[cur] = 0;
		long long count = 0;
		for (int i = 0; i < top[!cur]; ++i)
		{
			count += dp[!cur][i].num / mod * dp[!cur][i].count;
			dp[cur][top[cur]++] = (Pair){dp[!cur][i].num % mod, dp[!cur][i].count};
		}
		dp[cur][top[cur]++] = (Pair){mod, count};
	}
	long long ans = 0;
	for (int i = 0; i < top[cur]; ++i)
	{
		ans += dp[cur][i].num * (dp[cur][i].num - 1) / 2 * dp[cur][i].count;
	}
	printf("%lld\n", ans);
	return 0;
}
