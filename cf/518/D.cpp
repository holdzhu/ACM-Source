#include <cstdio>

int main()
{
	int n, t;
	double p;
	scanf("%d %lf %d", &n, &p, &t);
	if (t <= n)
	{
		printf("%lf\n", p * t);
	}
	else
	{
		double pt[t + 1];
		double npt[t + 1];
		pt[0] = 1;
		npt[0] = 1;
		for (int i = 1; i <= t; ++i)
		{
			pt[i] = pt[i - 1] * p;
			npt[i] = npt[i - 1] * (1 - p);
		}
		double s = 0;
		for (int i = 1; i < n; ++i)
		{
			double d = 1;
			for (int j = 0; j < i; ++j)
			{
				d *= t - j;
				d /= j + 1;
			}
			s += d * i * pt[i] * npt[t - i];
		}
		for (int i = n - 1; i <= t - 1; ++i)
		{
			double d = 1;
			for (int j = 0; j < n - 1; ++j)
			{
				d *= i - j;
				d /= j + 1;
			}
			s += d * n * pt[n] * npt[i - n + 1];
		}
		printf("%lf\n", s);
	}
	return 0;
}
