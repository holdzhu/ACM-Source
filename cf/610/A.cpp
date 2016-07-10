#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", (n + 1) % 2 * n / 4 - (n % 4 == 0));
	return 0;
}
