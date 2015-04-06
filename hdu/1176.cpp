#include <cstdio>
#include <cstring>

int a[100005][11];

int main()
{
	int n;
	while (scanf("%d", &n) == 1 && n)
	{
		memset(a, 0, sizeof(a));
		int maxT = 0;
		for (int i = 0; i < n; ++i)
		{
			int x, T;
			scanf("%d %d", &x, &T);
			a[T][x]++;
			if (T > maxT)
			{
				maxT = T;
			}
		}
		for (int i = maxT - 1; i >= 0; --i)
		{
			for (int j = 0; j <= 10; ++j)
			{
				int max = a[i + 1][j];
				if (j > 0 && a[i + 1][j - 1] > max)
				{
					max = a[i + 1][j - 1];
				}
				if (j < 10 && a[i + 1][j + 1] > max)
				{
					max = a[i + 1][j + 1];
				}
				a[i][j] += max;
			}
		}
		printf("%d\n", a[0][5]);
	}
	return 0;
}
