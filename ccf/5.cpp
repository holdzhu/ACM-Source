#include <cstdio>
#include <cstring>

int R, C;
char s[50][51];
bool svis[50][50];
bool tvis[50][50];
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};

inline bool isvalid(int x, int y)
{
	return x >= 0 && y >= 0 && x < R && y < C && s[x][y] != '#';
}

inline bool canmove(int x0, int y0, int x, int y)
{
	if (!isvalid(x0, y0) || !isvalid(x, y))
	{
		return false;
	}
	switch (s[x0][y0])
	{
	case '+': case 'S': case 'T':
		return true;
		break;
	case '-':
		return y0 + 1 == y || y0 - 1 == y;
		break;
	case '|':
		return x0 + 1 == x || x0 - 1 == x;
		break;
	case '.':
		return x0 + 1 == x;
		break;
	}
	return false;
}

void sdfs(int x, int y)
{
	if (!isvalid(x, y) || svis[x][y])
	{
		return;
	}
	svis[x][y] = true;
	for (int i = 0; i < 4; ++i)
	{
		if (canmove(x, y, x + dx[i], y + dy[i]))
		{
			sdfs(x + dx[i], y + dy[i]);
		}
	}
}

void tdfs(int x, int y)
{
	if (!isvalid(x, y) || tvis[x][y])
	{
		return;
	}
	tvis[x][y] = true;
	for (int i = 0; i < 4; ++i)
	{
		if (canmove(x + dx[i], y + dy[i], x, y))
		{
			tdfs(x + dx[i], y + dy[i]);
		}
	}
}

int main()
{
	scanf("%d %d", &R, &C);
	int sx, sy;
	int tx, ty;
	for (int i = 0; i < R; ++i)
	{
		scanf("%s", s[i]);
		for (int j = 0; j < C; ++j)
		{
			if (s[i][j] == 'S')
			{
				sx = i;
				sy = j;
			}
			else if (s[i][j] == 'T')
			{
				tx = i;
				ty = j;
			}
		}
	}
	memset(svis, false, sizeof svis);
	memset(tvis, false, sizeof tvis);
	sdfs(sx, sy);
	tdfs(tx, ty);
	if (!svis[tx][ty])
	{
		printf("I'm stuck!\n");
	}
	else
	{
		int cnt = 0;
		for (int i = 0; i < R; ++i)
		{
			for (int j = 0; j < C; ++j)
			{
				if (svis[i][j] && !tvis[i][j])
				{
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
