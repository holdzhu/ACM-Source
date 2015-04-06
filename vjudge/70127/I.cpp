#include <cstdio>
#include <cmath>

int main()
{
	int n;
	while (scanf("%d", &n) == 1 && n)
	{
		int x[n], y[n];
		for (int i = 0; i < n; ++i)
		{
			scanf("%d %d", &x[i], &y[i]);
		}
		int maxl = 0;
		for (int i = 0; i < 10000; ++i)
		{
			double ix = cos(i * 0.00031415926535);
			double iy = sin(i * 0.00031415926535);
			int dx = 0;
			int dy = 0;
			for (int j = 0; j < n; ++j)
			{
				if (ix * y[j] + x[j] * iy >= 0)
				{
					dx += x[j];
					dy += y[j];
				}
				else
				{
					dx -= x[j];
					dy -= y[j];
				}
			}
			if (dx * dx + dy * dy > maxl)
			{
				maxl = dx * dx + dy * dy;
			}
		}
		printf("%.3lf\n", sqrt(maxl));
	}
	return 0;
}
