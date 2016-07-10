#include <cstdio>
#include <cmath>

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	double delta = sqrt(b * b - 4 * a * c);
	double x1 = (-b + delta) / 2 / a;
	double x2 = (-b - delta) / 2 / a;
	printf("%.10f\n%.10f\n", fmax(x1, x2), fmin(x1, x2));
	return 0;
}
