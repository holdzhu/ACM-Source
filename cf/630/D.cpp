#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);
	printf("%I64d\n", 1ll * n * (n + 1) * 3 + 1);
	return 0;
}
