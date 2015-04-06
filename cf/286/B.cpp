#include <cstdio>
#include <cstring>

int p[100][100];

int find(int color, int x)
{
	return p[color][x] == x ? x : p[color][x] = find(color, p[color][x]);
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	memset(p, 0, sizeof(p));
	for (int i = 0; i < 100; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			p[i][j] = j;
		}
	}
	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		int x = find(c - 1, a - 1);
		int y = find(c - 1, b - 1);
		p[c - 1][x] = y;
	}
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		int s = 0;
		for (int i = 0; i < 100; ++i)
		{
			int x = find(i, u - 1);
			int y = find(i, v - 1);
			if (x == y)
			{
				s++;
			}
		}
		printf("%d\n", s);

	}
	return 0;
}
