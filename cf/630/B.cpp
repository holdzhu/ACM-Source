#include <cstdio>
#include <cmath>

int main()
{
	int n, t;
	scanf("%d %d", &n, &t);
	printf("%.10f\n", (double)(n * powl(1.000000011l, t)));
	return 0;
}
