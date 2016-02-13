#include <cstdio>

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n / 2 + 1; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			putchar('#');
		}
		printf("\n");
		if (i != n / 2)
		{
			for (int j = 0; j < m; ++j)
			{
				if (i % 2 == 1 && j == 0)
				{
			putchar('#');
				}
				else if (i % 2 == 0 && j == m - 1)
				{
			putchar('#');
				}
				else
				{
					putchar('.');
				}
			}
		printf("\n");
		}
	}
	return 0;
}
