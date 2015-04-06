#include <cstdio>

int main()
{
	const int d[] = {0, 0, 1, 0, -1, 0, 0, 1, 0, -1};
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int m, n;
		scanf("%d %d", &m, &n);
		double a[m][n];
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				scanf("%lf", &a[i][j]);
			}
		}
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				int l = 0;
				double s = 0;
				for (int k = 0; k < 5; ++k)
				{
					int dx = i + d[k * 2];
					int dy = j + d[k * 2 + 1];
					if (dx >= 0 && dy >= 0 && dx < m && dy < n)
					{
						s += a[dx][dy];
						l++;
					}
				}
				printf("%.2lf ", s / l);
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
