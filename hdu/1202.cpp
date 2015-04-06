#include <cstdio>

int point(double x)
{
	if (x >= 90)
	{
		return 4;
	}
	if (x >= 80)
	{
		return 3;
	}
	if (x >= 70)
	{
		return 2;
	}
	if (x >= 60)
	{
		return 1;
	}
	return 0;
}

int main()
{
	int N;
	while (scanf("%d", &N) == 1)
	{
		double ss = 0;
		double sp = 0;
		while (N--)
		{
			double s, p;
			scanf("%lf %lf", &s, &p);
			if (p >= 0)
			{
				int t = point(p) * s;
				ss += s;
				sp += t;
			}
		}
		if (sp == 0)
		{
			printf("-1\n");
		}
		else
		{
			printf("%.2f\n", sp / ss);
		}
	}
	return 0;
}
