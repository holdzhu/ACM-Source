#include <cstdio>
#include <cstring>

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
int n, m;
char s[50][51];
bool vis[50][50];

inline bool isValid(int x, int y)
{
	return x >= 0 && y >= 0 && x < n && y < m;
}

bool dfs(int x, int y, char c, int lx, int ly)
{
	vis[x][y] = true;
	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (isValid(nx, ny) && s[nx][ny] == c)
		{
			if (!(nx == lx && ny == ly) && vis[nx][ny])
			{
				return true;
			}
			if (!vis[nx][ny] && dfs(nx, ny, c, x, y))
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", s[i]);
	}
	bool flag = false;
	for (int i = 0; i < 26; ++i)
	{
		memset(vis, 0, sizeof vis);
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < m; ++k)
			{
				if (s[j][k] == i + 'A' && !vis[j][k])
				{
					flag |= dfs(j, k, i + 'A', -1, -1);
				}
			}
		}
	}
	puts(flag ? "Yes" : "No");
	return 0;
}
