#include <cstdio>
#include <cmath>

int main()
{
	int x, y, r;
	scanf("%d %d %d", &x, &y, &r);
	printf("%.15f\n", log(x * x + y * y) * acos(-1) * r * r);
	return 0;
}
