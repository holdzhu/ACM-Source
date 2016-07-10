#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

const int blocks = 1500;

const int p[14] = {3, 5, 7, 11, 13, 15, 17, 23, 29, 31, 37, 41, 43, 47};

int x1, Y1, x2, y2, x3, y3;

inline double check(double x, double y)
{
	return hypot(x - x1, y - Y1) + 2 * hypot(x - x2, y - y2) + 3 * hypot(x - x3, y - y3);
}

int ite;

double check(double x, double ly, double ry)
{
	for (int i = 0; i < 300; ++i)
	{
		double mid1 = ly + (ry - ly) / p[ite];
		double mid2 = ly + ry - mid1;
		if (check(x, mid1) < check(x, mid2))
			ry = mid2;
		else
			ly = mid1;
	}
	return check(x, (ly + ry) / 2);
}

int main()
{
	scanf("%d %d %d %d %d %d", &x1, &Y1, &x2, &y2, &x3, &y3);
	int maxx = max({x1, x2, x3});
	int minx = min({x1, x2, x3});
	int maxy = max({Y1, y2, y3});
	int miny = min({Y1, y2, y3});
	double lenx = (maxx - minx) * 1.0 / blocks;
	double leny = (maxy - miny) * 1.0 / blocks;
	double val = 1e233;
	int px = 0;
	int py = 0;
	for (int i = 0; i <= blocks; ++i)
		for (int j = 0; j <= blocks; ++j)
		{
			double newval = check(minx + lenx * i, miny + leny * j);
			if (newval < val)
			{
				val = newval;
				px = i;
				py = j;
			}
		}
	double lx = minx + lenx * px - lenx;
	double rx = minx + lenx * px + lenx;
	double ly = miny + leny * py - leny;
	double ry = miny + leny * py + leny;
	double ans = 1e233;
	for (ite = 0; ite < 14; ++ite)
	{
		for (int i = 0; i < 300; ++i)
		{
			double mid1 = lx + (rx - lx) / p[ite];
			double mid2 = lx + rx - mid1;
			if (check(mid1, ly, ry) < check(mid2, ly, ry))
				rx = mid2;
			else
				lx = mid1;
		}
		ans = min(ans, check((lx + rx) / 2, ly, ry));
	}
	printf("%.6f\n", ans);
	return 0;
}
