#include <cstdio>
#include <cmath>

const double pi = acos(-1);

int main()
{
	int n, r;
	scanf("%d %d", &n, &r);
	printf("%.10f\n", 1.0 * n * r * r * sin(pi / n) * sin(pi / 2 / n) / sin(3 * pi / 2 / n));
	return 0;
}
