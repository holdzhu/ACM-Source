#include <cstdio>
#include <cmath>

const long double pi = acosl(-1);

int main()
{
	double _x1, _y1, _r1, _x2, _y2, _r2;
	scanf("%lf %lf %lf %lf %lf %lf", &_x1, &_y1, &_r1, &_x2, &_y2, &_r2);
	long double x1 = _x1, y1 = _y1, r1 = _r1, x2 = _x2, y2 = _y2, r2 = _r2;
	long double r = hypotl(x1 - x2, y1 - y2);
	if (r >= r1 + r2)
	{
		puts("0");
	}
	else if (r + r1 <= r2)
	{
		printf("%.10f\n", (double)(pi * r1 * r1));
	}
	else if (r + r2 <= r1)
	{
		printf("%.10f\n", (double)(pi * r2 * r2));
	}
	else
	{
		long double rs = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
		long double a1 = acosl((r1 * r1 + rs - r2 * r2) / (2 * r1 * r));
		long double a2 = acosl((r2 * r2 + rs - r1 * r1) / (2 * r2 * r));
		printf("%.10f\n", (double)((a1 - sinl(a1 * 2) / 2) * r1 * r1 + (a2 - sinl(a2 * 2) / 2) * r2 * r2));
	}
	return 0;
}
