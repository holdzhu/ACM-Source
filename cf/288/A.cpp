#include <cstdio>
#include <cstring>

int main()
{
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	bool a[n][m];
	memset(a, 0, sizeof(a));
	bool b = false;
	for (int t = 0; t < k; ++t)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		x--;
		y--;
		if (!a[x][y])
		{
			a[x][y] = true;
			for (int i = -1; i <= 1 && !b; i += 2)
			{
				for (int j = -1; j <= 1; j += 2)
				{
					int dx = x + i;
					int dy = y + j;
					if (dx >= 0 && dy >= 0 && dx < n && dy < m
						&& a[dx][dy] && a[x][dy] && a[dx][y])
					{
						b = true;
					}
				}
			}
		}
		if (b)
		{
			printf("%d\n", t + 1);
			break;
		}
	}
	if (!b)
	{
		printf("0\n");
	}
	return 0;
}
