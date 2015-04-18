#include <cstdio>
#include <cstring>

char s[1001];
long long dp[1000][1000];
bool vis[1000][1000];

long long f(int l, int r)
{
	if (l < 0 || r < 0)
	{
		return 0;
	}
	if (l > r)
	{
		return 1;
	}
	if (!vis[l][r])
	{
		vis[l][r] = true;
		dp[l][r] = f(l + 1, r) + f(l, r - 1);
		if (s[l] != s[r])
		{
			dp[l][r] -= f(l + 1, r - 1);
		}
		dp[l][r] %= 100007;
	}
	return dp[l][r];
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		scanf("%s", s);
		int l = strlen(s);
		memset(dp, 0, sizeof dp);
		memset(vis, 0, sizeof vis);
		for (int i = 0; i < l; ++i)
		{
			dp[i][i] = 2;
			vis[i][i] = true;
		}
		long long ans = f(0, l - 1) - 1;
		ans %= 100007;
		if (ans < 0)
		{
			ans += 100007;
		}
		printf("Case #%d: %lld\n", kase, ans);
	}
	return 0;
}
