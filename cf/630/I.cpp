#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);
	printf("%I64u\n", 3 * (1ull << (2 * n - 3)) + (n - 3) * 9 * (1ull << (2 * n - 6)));
	return 0;
}
