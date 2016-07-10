#include <cstdio>
#include <cstring>

const int mod = 1e9 + 7;
const char type[] = "()[]";

int n;
char s[301];
int nxt[301][128];
int dp[300][300];

int solve(int l = 0, int r = n - 1)
{
	if (l >= r)
		return 1;
	if (dp[l][r] != -1)
		return dp[l][r];
	dp[l][r] = 1;
	for (int i = nxt[l]['(']; i < r; i = nxt[i + 1]['('])
		for (int j = nxt[i][')']; j <= r; j = nxt[j + 1][')'])
		{
			dp[l][r] += 1ll * solve(i + 1, j - 1) * solve(j + 1, r) % mod;
			if (dp[l][r] >= mod)
				dp[l][r] -= mod;
		}
	for (int i = nxt[l]['[']; i < r; i = nxt[i + 1]['['])
		for (int j = nxt[i][']']; j <= r; j = nxt[j + 1][']'])
		{
			dp[l][r] += 1ll * solve(i + 1, j - 1) * solve(j + 1, r) % mod;
			if (dp[l][r] >= mod)
				dp[l][r] -= mod;
		}
	return dp[l][r];
}

int main()
{
	scanf("%d %s", &n, s);
	for (int i = 0; i < 4; ++i)
		nxt[n][type[i]] = n;
	for (int i = n - 1; i >= 0; --i)
		for (int j = 0; j < 4; ++j)
			nxt[i][type[j]] = s[i] == type[j] ? i : nxt[i + 1][type[j]];
	memset(dp, -1, sizeof dp);
	printf("%d\n", (solve() + mod - 1) % mod);
	return 0;
}