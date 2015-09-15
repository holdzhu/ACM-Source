#include <cstdio>
#include <cstring>

const int mod = 1e9 + 7;
int l;
char s[100005];
long long dp[100005][16];

long long solve()
{
	long long ret = 0;
	long long xr = 0;
	for (int i = 0; i < l; ++i)
	{
		for (int j = 0; j < s[i] - '0'; ++j)
		{
			for (int k = 0; k < 16; ++k)
			{
				ret = (ret + dp[l - i - 1][k] * (k ^ j ^ xr)) % mod;
			}
		}
		xr ^= s[i] - '0';
	}
	return ret;
}

int main()
{
	dp[0][0] = 1;
	for (int i = 1; i < 100005; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			for (int k = 0; k < 16; ++k)
			{
				dp[i][k] = dp[i][k] + dp[i - 1][k ^ j];
				if (dp[i][k] >= mod)
				{
					dp[i][k] -= mod;
				}
			}
		}
	}
	int T;
	scanf("%d", &T);
	for (int k = 1; k <= T; ++k)
	{
		scanf("%s", s);
		l = strlen(s);
		long long ans = solve();
		ans = -ans;
		scanf("%s", s);
		l = strlen(s);
		int xr = 0;
		for (int i = 0; i < l; ++i)
		{
			xr ^= s[i] - '0';
		}
		ans = (ans + solve() + xr) % mod;
		if (ans < 0)
		{
			ans += mod;
		}
		printf("Case #%d: %I64d\n", k, ans);
	}
	return 0;
}
