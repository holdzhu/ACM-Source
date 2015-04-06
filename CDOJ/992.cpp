#include <cstdio>

int main()
{
	double r;
	int n;
	while (scanf("%lf %d", &r, &n) == 2)
	{
		printf("%.2lf\n", r * 6.283185307179586476925286766559 * n);
	}
	return 0;
}
