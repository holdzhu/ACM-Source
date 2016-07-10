#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);
	printf("%I64d\n", 1ll * n * (n - 1) / 2 * (n - 2) / 3 * (n - 3) / 4 * (n - 4) / 5 * (n - 5) / 6 * (n - 6) / 7
					+ 1ll * n * (n - 1) / 2 * (n - 2) / 3 * (n - 3) / 4 * (n - 4) / 5 * (n - 5) / 6
					+ 1ll * n * (n - 1) / 2 * (n - 2) / 3 * (n - 3) / 4 * (n - 4) / 5);
	return 0;
}
