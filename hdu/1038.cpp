#include <cstdio>
#include <cmath>

int main()
{
	double a, c;
	int b;
	int kase = 1;
	while (scanf("%lf %d %lf", &a, &b, &c) == 3 && b)
	{
		printf("Trip #%d: %.2f %.2f\n", kase++, a * acos(-1) * b / 12 / 5280, a * acos(-1) * b / 12 / 5280 / c * 3600);
	}
	return 0;
}
