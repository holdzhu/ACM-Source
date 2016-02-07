#include <cstdio>
#include <cmath>

int main()
{
	double x1, x2, y1, y2;
	scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
	double vm, t;
	scanf("%lf %lf", &vm, &t);
	double vx, vy, wx, wy;
	scanf("%lf %lf %lf %lf", &vx, &vy, &wx, &wy);
	double L = 0;
	double R = t + 1;
	for (int i = 0; i < 200; ++i)
	{
		double M = (L + R) / 2;
		double px = (x2 - x1) / M - vx;
		double py = (y2 - y1) / M - vy;
		if (hypot(px, py) < vm)
		{
			R = M;
		}
		else
		{
			L = M;
		}
	}
	if (L <= t + 1e-15)
	{
		printf("%.18f\n", L);
	}
	else
	{
		L = t;
		R = 1e12;
		for (int i = 0; i < 200; ++i)
		{
			double M = (L + R) / 2;
			double px = (x2 - x1 + (wx - vx) * t) / M - wx;
			double py = (y2 - y1 + (wy - vy) * t) / M - wy;
			if (hypot(px, py) < vm)
			{
				R = M;
			}
			else
			{
				L = M;
			}
		}
		printf("%.18f\n", L);
	}
	return 0;
}
