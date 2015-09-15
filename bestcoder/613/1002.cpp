#include <cstdio>
#include <cstring>

bool vis[9][9];

int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		memset(vis, 0, sizeof vis);
		for (int i = 0; i < n; ++i)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			vis[x][y] = true;
		}
		int ans = 0;
		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				for (int r = 1; i + r <= 8 && j + r <= 8; ++r)
				{
					if (vis[i][j] && vis[i][j + r] && vis[i + r][j] && vis[i + r][j + r])
					{
						ans++;
					}
				}
			}
		}
		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				for (int r = 1; i + r <= 8 && j + r <= 8; ++r)
				{
					for (int k = 1; k < r; ++k)
					{
						if (vis[i + k][j] && vis[i][j + r - k] && vis[i + r - k][j + r] && vis[i + r][j + k])
						{
							ans++;
						}
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
