#include <cstdio>

int main()
{
	int a, b, c, d, e;
	scanf("%1d%1d%1d%1d%1d", &a, &e, &b, &d, &c);
	int n = a * 10000 + b * 1000 + c * 100 + d * 10 + e;
	printf("%05I64d\n", 1ll * n * n % 100000 * n % 100000 * n % 100000 * n % 100000);
	return 0;
}