#include <cstdio>
#include <cmath>

const double eps = 1e-8;

int a, b, c, x, y;

inline double check(double t)
{
	return (a * t * t + b * t + c - y) * (a * t * t + b * t + c - y) + (x - t) * (x - t);
}

int main()
{
	scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);
	double L = -100000;
	double R = 100000;
	while (R - L >= eps)
	{
		double l = L + (R - L) / 3;
		double r = R - (R - L) / 3;
		double d1 = check(l);
		double d2 = check(r);
		if (d1 <= d2)
		{
			R = r;
		}
		if (d1 >= d2)
		{
			L = l;
		}
	}
	printf("%.3f\n", sqrt(check((R + L) / 2)));
	return 0;
}
