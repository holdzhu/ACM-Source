#include <cstdio>
#include <cmath>

int main()
{
	double a, b;
	scanf("%lf %lf", &a, &b);
	puts(fabs(a - b) < 1e-8 ? "yes" : "no");
	return 0;
}
