#include <cstdio>
#include <cmath>
#include <random>
#include <algorithm>

using namespace std;

const int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const double r = 0.99992;

int X1, Y1, X2, Y2, X3, Y3;

inline double solve(double x, double y)
{
	return hypot(x - X1, y - Y1) + hypot(x - X2, y - Y2) * 2 + hypot(x - X3, y - Y3) * 3;
}

int main()
{
	default_random_engine rnd(0x772002);
	uniform_real_distribution<double> dis(0, 1);
	scanf("%d %d %d %d %d %d", &X1, &Y1, &X2, &Y2, &X3, &Y3);
	double x = (X1 + X2 + X3) / 3.0;
	double y = (Y1 + Y2 + Y3) / 3.0;
	double T = 1e8;
	double e = solve(x, y);
	for (int i = 0; i < 1e6; ++i)
	{
		double men = 1e233;
		double mxn, myn;
		for (int j = 0; j < 8; ++j)
		{
			double xn = x + T * dx[j];
			double yn = y + T * dy[j];
			double en = solve(xn, yn);
			if (men > en)
			{
				mxn = xn;
				myn = yn;
				men = en;
			}
		}
		if (men < e || exp(-(men - e) / (2 * T)) < dis(rnd))
		{
			x = mxn;
			y = myn;
			e = men;
		}
		T *= r;
	}
	printf("%.10f\n", (double)solve(round(x), round(y)));
	return 0;
}