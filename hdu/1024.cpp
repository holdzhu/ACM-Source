#include <cstdio>
#include <cstring>

#define INF 100000000

int main()
{
	int m, n;
	while (scanf("%d %d", &m, &n) == 2)
	{
		int a[n];
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &a[i]);
		}
		int d[2][n];
		int cur = 0;
		memset(d, 0, sizeof(d));
		int max = 0;
		for (int i = 0; i < m; ++i)
		{
			cur ^= 1;
			for (int j = i; j < n - m + i + 1; ++j)
			{
				d[cur][j] = max + a[j];
				if (j > i && d[cur][j] < d[cur][j - 1] + a[j])
				{
					d[cur][j] = d[cur][j - 1] + a[j];
				}
				if (max < d[cur ^ 1][j])
				{
					max = d[cur ^ 1][j];
				}
			}
			max = d[cur][i];
		}
		for (int i = m - 1; i < n; ++i)
		{
			if (max < d[cur][i])
			{
				max = d[cur][i];
			}
		}
		printf("%d\n", max);
	}
	return 0;
}
