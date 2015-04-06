#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int t;
		double a, b, c, d;
		scanf("%d%lf%lf%lf%lf", &t, &a, &b, &c, &d);
		printf("%d %.2lf\n", t, a / (b + c) * d);
	}
	return 0;
}
