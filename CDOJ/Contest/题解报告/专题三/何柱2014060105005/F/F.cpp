#include <cstdio>
#include <cstring>

enum
{
	Girl,
	Qiu,
	Jiang
};

double dp[1001][1001][3];

double dfs(int w, int b, int player)
{
	if (!(w | b))
	{
		return 0;
	}
	if (dp[w][b][player] != dp[w][b][player])
	{
		dp[w][b][player] = 0;
		if (w)
		{
			if (player == Girl)
			{
				dp[w][b][player] += w * 1.0 / (w + b);
			}
			else if (player == Jiang)
			{
				dp[w][b][player] += w * 1.0 / (w + b) * dfs(w - 1, b, (player + 1) % 3);
			}
		}
		if (b)
		{
			dp[w][b][player] += b * 1.0 / (w + b) * dfs(w, b - 1, (player + 1) % 3);
		}
	}
	return dp[w][b][player];
}

int main()
{
	memset(dp, -1, sizeof dp);
	int w, b;
	scanf("%d %d", &w, &b);
	printf("%.9f\n", dfs(w, b, Girl));
	return 0;
}
