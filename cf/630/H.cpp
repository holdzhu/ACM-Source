#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);
	printf("%I64u\n", 1ull * n * (n - 1) / 2 * (n - 2) / 3 * (n - 3) / 4 * (n - 4) / 5 * n * (n - 1) * (n - 2) * (n - 3) * (n - 4));
	return 0;
}
