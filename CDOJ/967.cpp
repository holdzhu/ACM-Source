#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int m, n;
		scanf("%d %d", &m, &n);
		int a[m][n];
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				scanf("%d", &a[i][j]);
			}
		}
		if (n < m)
		{
			m = n;
		}
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (i + j >= n)
				{
					printf(" ");
				}
				else
				{
					printf("%d", a[i][j]);
				}
			}
			for (int j = n - 2; j >= 0; --j)
			{
				if (i + j >= n)
				{
					printf(" ");
				}
				else
				{
					printf("%d", a[i][j]);
				}
			}
			printf("\n");
		}
		for (int i = m - 2; i >= 0; --i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (i + j >= n)
				{
					printf(" ");
				}
				else
				{
					printf("%d", a[i][j]);
				}
			}
			for (int j = n - 2; j >= 0; --j)
			{
				if (i + j >= n)
				{
					printf(" ");
				}
				else
				{
					printf("%d", a[i][j]);
				}
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
