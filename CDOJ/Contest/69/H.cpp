#include <cstdio>
#include <cstring>

const int mod = 1000000007;
long long dp[1002][1001][5];

long long dfs(int n, int k, int type)
{
	if (n < 0 || k < 0 || k > n)
	{
		return 0;
	}
	if (dp[n][k][type] == -1)
	{
		switch (type)
		{
		case 0:
			dp[n][k][type] = dfs(n - 1, k, 0) + 
							dfs(n - 1, k, 1) + 
							dfs(n - 1, k, 2) + 
							dfs(n - 1, k, 3) + 
							dfs(n - 1, k, 4);
			break;
		case 1:
			dp[n][k][type] = dfs(n - 1, k - 1, 1) + 
							dfs(n - 1, k, 2) + 
							dfs(n - 1, k - 1, 3) + 
							dfs(n - 1, k, 4);
			break;
		case 2:
			dp[n][k][type] = dfs(n - 1, k - 2, 0);
			break;
		case 3:
			dp[n][k][type] = dfs(n - 1, k + 1, 0) * (k + 1) % mod +
							dfs(n - 1, k, 0) * (n - k - 2) % mod +
							dfs(n - 1, k + 1, 1) * k % mod +
							dfs(n - 1, k, 1) * (n - k - 2) % mod +
							dfs(n - 1, k + 1, 2) * (k - 1) % mod +
							dfs(n - 1, k, 2) * (n - k - 1) % mod +
							dfs(n - 1, k + 1, 3) * (k + 1) % mod +
							dfs(n - 1, k, 3) * (n - k - 3) % mod +
							dfs(n - 1, k + 1, 4) * k % mod +
							dfs(n - 1, k, 4) * (n - k - 2) % mod;
			break;
		case 4:
			dp[n][k][type] = dfs(n - 1, k, 1) + 
							dfs(n - 1, k, 2) + 
							dfs(n - 1, k - 1, 3) + 
							dfs(n - 1, k - 1, 4);
			break;
		}
		dp[n][k][type] %= mod;
	}
	return dp[n][k][type];
}

int main()
{
	int n, k;
	memset(dp, -1, sizeof dp);
	scanf("%d %d", &n, &k);
	dp[1][0][0] = 1;
	printf("%lld\n", dfs(n + 1, k, 0));
	return 0;
}
