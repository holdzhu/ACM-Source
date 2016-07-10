#include <cstdio>

int main()
{
	int x1, y1, x2, y2;
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	printf("%I64d\n", 1ll * (x2 - x1) / 2 * (y2 - y1 + 1) + (y2 - y1 + 2) / 2);
	return 0;
}
