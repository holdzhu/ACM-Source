#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>

using namespace std;

int p[2000];
int dp[2001][21];
int prefix[2001];

int round(int x)
{
	int ten = x / 10;
	int unit = x % 10;
	if (unit < 5)
	{
		return ten * 10;
	}
	return ten * 10 + 10;
}

int dfs(int n, int d)
{
	if (n == 0)
	{
		return 0;
	}
	if (d == 0)
	{
		return round(prefix[n]);
	}
	if (dp[n][d] == -1)
	{
		dp[n][d] = INT_MAX;
		for (int i = 0; i <= n; ++i)
		{
			dp[n][d] = min(dp[n][d], dfs(i, d - 1) + round(prefix[n] - prefix[i]));
		}
	}
	return dp[n][d];
}

int main()
{
	int n, d;
	scanf("%d %d", &n, &d);
	prefix[0] = 0;
	memset(dp, -1, sizeof dp);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &p[i]);
		prefix[i + 1] = prefix[i] + p[i];
	}
	printf("%d\n", dfs(n, d));
	return 0;
}
