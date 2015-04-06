#include <cstdio>
#include <cmath>

double cross(double x1, double y1, double x2, double y2)
{
	return x1 * y2 - x2 * y1;
}

int main()
{
	int N;
	scanf("%d", &N);
	double x[N], y[N];
	for (int i = 0; i < N; ++i)
	{
		scanf("%lf %lf", &x[i], &y[i]);
	}
	double cx, cy;
	scanf("%lf %lf", &cx, &cy);
	double ans = 0;
	for (int i = 0; i < N; ++i)
	{
		if (cross(x[i] - cx, y[i] - cy, x[(i + 1) % N] - cx, y[(i + 1) % N] - cy) < 0)
		{
			ans += sqrt((x[(i + 1) % N] - x[i]) * (x[(i + 1) % N] - x[i]) + (y[(i + 1) % N] - y[i]) * (y[(i + 1) % N] - y[i]));
		}
	}
	printf("%.3lf\n", ans);
	return 0;
}
