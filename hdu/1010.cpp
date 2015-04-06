#include <cstdio>
#include <cstdlib>
#include <cstring>

const int d[] = {0, 1, 0, -1, 1, 0, -1, 0};
char a[6][7];
bool vis[6][6];
int N, M, T;
int sx, sy, ex, ey;

bool dfs(int x, int y, int step)
{
	if (T - step < abs(x - ex) + abs(y - ey))
	{
		return false;
	}
	if (a[x][y] == 'D')
	{
		return step == T;
	}
	for (int i = 0; i < 4; ++i)
	{
		int dx = x + d[i * 2];
		int dy = y + d[i * 2 + 1];
		if (!vis[dx][dy] && a[dx][dy] != 'X' && dx >= 0 && dy >= 0 && dx < N && dy < M)
		{
			vis[dx][dy] = true;
			if (dfs(dx, dy, step + 1))
			{
				return true;
			}
			vis[dx][dy] = false;
		}
	}
	return false;
}

int main()
{
	while (scanf("%d %d %d", &N, &M, &T) == 3 && N && M && T)
	{
		for (int i = 0; i < N; ++i)
		{
			scanf("%s", a[i]);
			for (int j = 0; j < M; ++j)
			{
				if (a[i][j] == 'S')
				{
					sx = i;
					sy = j;
				}
				else if (a[i][j] == 'D')
				{
					ex = i;
					ey = j;
				}
			}
		}
		if ((sx + sy + ex + ey + T) % 2)
		{
			printf("NO\n");
			continue;
		}
		memset(vis, 0, sizeof(vis));
		vis[sx][sy] = true;
		if (dfs(sx, sy, 0))
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}
