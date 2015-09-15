#include <cstdio>

int main()
{
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	int x = 1, y = 1;
	for (int i = 0; i < k; ++i)
	{
		int t = i < k - 1 ? 2 : n * m - 2 * (k - 1);
		printf("%d", t);
		for (int j = 0; j < t; ++j)
		{
			printf(" %d %d", x, y);
			if (x & 1)
			{
				if (y == m)
				{
					x++;
				}
				else
				{
					y++;
				}
			}
			else
			{
				if (y == 1)
				{
					x++;
				}
				else
				{
					y--;
				}
			}
		}
		puts("");
	}
	return 0;
}
