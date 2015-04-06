#include <cstdio>
#include <cstring>

int main()
{
	int n, m;
	while (scanf("%d %d", &n, &m) == 2 && n && m)
	{
		int p;
		scanf("%d", &p);
		char s[n][m + 1];
		for (int i = 0; i < n; ++i)
		{
			scanf("%s", s[i]);
		}
		int c[n][m];
		memset(c, 0, sizeof(c));
		int x = 0;
		int y = p - 1;
		int t = 1;
		while (true)
		{
			if (x < 0 || y < 0 || x >= n || y >= m)
			{
				printf("%d step(s) to exit\n", t - 1);
				break;
			}
			if (c[x][y] > 0)
			{
				printf("%d step(s) before a loop of %d step(s)\n", c[x][y] - 1, t - c[x][y]);
				break;
			}
			c[x][y] = t;
			if (s[x][y] == 'N')
			{
				x--;
			}
			else if (s[x][y] == 'S')
			{
				x++;
			}
			else if (s[x][y] == 'E')
			{
				y++;
			}
			else
			{
				y--;
			}
			t++;
		}
	}
	return 0;
}
