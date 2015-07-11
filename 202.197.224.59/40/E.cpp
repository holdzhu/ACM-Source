#include <cstdio>
#include <cmath>

const double pi = acos(-1);

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		double a, b;
		scanf("%lf %lf", &a, &b);
		a = a / 180 * pi;
		b = b / 180 * pi;
		double BO = sin(pi / 3 - a) / sin(pi / 3 * 2 + a - b);
		double CO = sqrt(BO * BO + 1 - 2 * BO * cos(pi / 3 - b));
		double x = asin(sin(pi / 3 - b) * BO / CO);
		x = x * 180 / pi;
		printf("%.2f\n", x);
	}
	return 0;
}
