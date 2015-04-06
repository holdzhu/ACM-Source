#include <cstdio>
#include <cmath>

int main()
{
	long long r, x, y, x1, y1;
	scanf("%I64d %I64d %I64d %I64d %I64d", &r, &x, &y, &x1, &y1);
	double d = sqrt((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y));
	printf("%d\n", (int)ceil(d / (r * 2)));
	return 0;
}
