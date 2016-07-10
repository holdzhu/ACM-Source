#include <cstdio>
#include <cmath>

int main()
{
	int d, h, v, e;
	scanf("%d %d %d %d", &d, &h, &v, &e);
	double ve = v / acos(-1) / (d / 2.) / (d / 2.);
	if (ve > e)
		printf("YES\n%.10f\n", h / (ve - e));
	else
		puts("NO");
	return 0;
}
