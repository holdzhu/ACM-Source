#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
char s[51][51];
double dp[51][51][51];
int n, m, k;
int x2, y2;

bool isvalid(int x, int y)
{
	return x >= 0 && y >= 0 && x < n && y < m && s[x][y] != '#';
}

double dfs(int x, int y, int kk)
{
	if (x == x2 && y == y2 && k >= kk)
	{
		return dp[x][y][kk] = 0;
	}
	if (kk == k)
	{
		return 1e18;
	}
	if (isnan(dp[x][y][kk]))
	{
		dp[x][y][kk] = 1e18;
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (isvalid(nx, ny))
			{
				dp[x][y][kk] = min(dp[x][y][kk], dfs(nx, ny, kk + 1) + abs(s[x][y] - s[nx][ny]) * 1.0 / (k + 1 - kk));
			}
		}
	}
	return dp[x][y][kk];
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		memset(dp, -1, sizeof dp);
		scanf("%d %d %d", &n, &m, &k);
		k--;
		for (int i = 0; i < n; ++i)
		{
			scanf("%s", s[i]);
		}
		int x1, y1;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		x1--;
		y1--;
		x2--;
		y2--;
		dfs(x1, y1, 0);
		if (isnan(dp[x1][y1][0]) || dp[x1][y1][0] == 1e18)
		{
			printf("No Answer\n");
		}
		else
		{
			printf("%.2f\n", dp[x1][y1][0]);
		}
	}
	return 0;
}
