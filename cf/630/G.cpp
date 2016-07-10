#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);
	printf("%I64u\n", (1ull * (n + 4) * (n + 3) / 2 * (n + 2) / 3 * (n + 1) / 4 * n / 5)
					 * (1ull * (n + 2) * (n + 1) / 2 * n / 3));
	return 0;
}
