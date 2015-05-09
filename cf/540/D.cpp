#include <cstdio>
#include <cstring>

double dp[3][101][101][101];
bool vis[3][101][101][101];

double dfs(int k, int x, int y, int z)
{
	if (x == 0 && y == 0 && z == 0)
	{
		return 0;
	}
	if (x == 0 && y == 0)
	{
		return k == 2;
	}
	if (x == 0 && z == 0)
	{
		return k == 1;
	}
	if (z == 0 && y == 0)
	{
		return k == 0;
	}
	if (x == 0)
	{
		return k == 1;
	}
	if (y == 0)
	{
		return k == 2;
	}
	if (z == 0)
	{
		return k == 0;
	}
	if (!vis[k][x][y][z])
	{
		if (k == 0)
		{
			dp[k][x][y][z] = dfs(k, x - 1, y, z) * x / (x + y + z) + dfs(k, x, y - 1, z) * y / (x + y + z);
		}
		else if (k == 1)
		{
			dp[k][x][y][z] = dfs(k, x, y - 1, z) * y / (x + y + z) + dfs(k, x, y, z - 1) * z / (x + y + z);
		}
		else
		{
			dp[k][x][y][z] = dfs(k, x, y, z - 1) * z / (x + y + z) + dfs(k, x - 1, y, z) * x / (x + y + z);
		}
		vis[k][x][y][z] = true;
	}
	printf("%d %d %d %d %.10f\n", k, x, y, z, dp[k][x][y][z]);
	return dp[k][x][y][z];
}

int main()
{
	int x, y, z;
	scanf("%d %d %d", &x, &y, &z);
	memset(vis, 0, sizeof vis);
	printf("%.10f %.10f %.10f\n", dfs(0, x, y, z), dfs(1, x, y, z), dfs(2, x, y, z));
	return 0;
}
