#include <cstdio>
#include <cstring>

int num[10];
int n;
int dp[10][11];

int dfs(int d = n, int last = 10, bool limit = true)
{
	if (d == 0)
	{
		return 1;
	}
	if (limit)
	{
		int rnt = 0;
		for (int i = 0; i <= num[d - 1]; ++i)
		{
			if (i != 4 && !(last == 6 && i == 2))
			{
				rnt += dfs(d - 1, i, i == num[d - 1]);
			}
		}
		return rnt;
	}
	else
	{
		if (dp[d][last] == -1)
		{
			dp[d][last] = 0;
			for (int i = 0; i < 10; ++i)
			{
				if (i != 4 && !(last == 6 && i == 2))
				{
					dp[d][last] += dfs(d - 1, i, false);
				}
			}
		}
		return dp[d][last];
	}
}

int solve(int x)
{
	n = 0;
	while (x)
	{
		num[n++] = x % 10;
		x /= 10;
	}
	return dfs();
}

int main()
{
	int l, r;
	memset(dp, -1, sizeof dp);
	while (scanf("%d %d", &l, &r) == 2 && l && r)
	{
		printf("%d\n", solve(r) - solve(l - 1));
	}
	return 0;
}
