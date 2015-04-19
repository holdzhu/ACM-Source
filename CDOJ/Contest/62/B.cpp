#include <cstdio>

char s[21][21];

const int d[] = {1, 0, -1, 0, 0, 1, 0, -1};

int main()
{
	int W, L;
	int HOUSE = 1;
	while (scanf("%d %d", &W, &L) == 2 && W && L)
	{
		int startx;
		int starty;
		for (int i = 0; i < L; ++i)
		{
			scanf("%s", s[i]);
			for (int j = 0; j < W; ++j)
			{
				if (s[i][j] == '*')
				{
					startx = i;
					starty = j;
				}
			}
		}
		int dir = -1;
		if (startx == 0)
		{
			dir = 0;
		}
		else if (startx == L - 1)
		{
			dir = 1;
		}
		else if (starty == 0)
		{
			dir = 2;
		}
		else
		{
			dir = 3;
		}
		while (1)
		{
			startx += d[dir * 2];
			starty += d[dir * 2 + 1];
			while (s[startx][starty] == '.')
			{
				startx += d[dir * 2];
				starty += d[dir * 2 + 1];
			}
			if (s[startx][starty] == 'x')
			{
				break;
			}
			if (s[startx][starty] == '/')
			{
				if (dir == 0)
				{
					dir = 3;
				}
				else if (dir == 1)
				{
					dir = 2;
				}
				else if (dir == 2)
				{
					dir = 1;
				}
				else
				{
					dir = 0;
				}
			}
			else
			{
				if (dir == 0)
				{
					dir = 2;
				}
				else if (dir == 1)
				{
					dir = 3;
				}
				else if (dir == 2)
				{
					dir = 0;
				}
				else
				{
					dir = 1;
				}
			}
		}
		printf("HOUSE %d\n", HOUSE++);
		for (int i = 0; i < L; ++i)
		{
			for (int j = 0; j < W; ++j)
			{
				if (i == startx && j == starty)
				{
					putchar('&');
				}
				else
				{
					putchar(s[i][j]);
				}
			}
			putchar('\n');
		}
	}
	return 0;
}
