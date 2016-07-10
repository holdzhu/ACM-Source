#include <cstdio>
#include <cmath>

const double pi = acos(-1);

double solve(double l, int n)
{
	return sqrt(1 - 1 / (4 * sin(pi / n) * sin(pi / n))) * n / tan(pi / n) * l * l * l / 12;
}

int main()
{
	int l3, l4, l5;
	scanf("%d %d %d", &l3, &l4, &l5);
	printf("%.10f\n", solve(l3, 3) + solve(l4, 4) + solve(l5, 5));
	return 0;
}
