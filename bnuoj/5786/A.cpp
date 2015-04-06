#include <cstdio>
#include <cmath>

double det(double a11, double a12, double a13, 
	double a21, double a22, double a23, 
	double a31, double a32, double a33)
{
	return a11 * a22 * a33 + a12 * a23 * a31 + a13 * a21 * a32
	- a11 * a23 * a32 - a12 * a21 * a33 - a13 * a22 * a13;
}

int main()
{
	int n;
	scanf("%d", &n);
	int x[n], y[n], z[n];
	double sx = 0;
	double sy = 0;
	double sz = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d %d", &x[i], &y[i], &z[i]);
		sx += x[i];
		sy += y[i];
		sz += z[i];
	}
	sx /= n;
	sy /= n;
	sz /= n;
	double mx1 = 1e8;
	for (int i = 0; i < n - 2; ++i)
	{
		for (int j = i + 1; j < n - 1; ++j)
		{
			for (int k = j + 1; k < n; ++k)
			{
				double dx = (y[i] - y[j]) * (z[i] - z[k]) - (y[i] - y[k]) * (z[i] - z[j]);
				double dy = (z[i] - z[j]) * (x[i] - x[k]) - (z[i] - z[k]) * (x[i] - x[j]);
				double dz = (x[i] - x[j]) * (y[i] - y[k]) - (x[i] - x[k]) * (y[i] - y[j]);
				double t = det(sx - x[i], sx - x[j], sx - x[k], 
					sy - y[i], sy - y[j], sy - y[k], sz - z[i], 
					sz - z[j], sz - z[k]) / sqrt(dx * dx + dy * dy + dz * dz);
				printf("%d %d %d %lf\n", i, j, k, t);
				if (t < 0)
				{
					t = -t;
				}
				if (mx1 > t)
				{
					mx1 = t;
				}
			}
		}
	}
	printf("%lf\n", mx1);
	return 0;
}
