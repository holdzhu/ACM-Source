#include <cstdio>

int main()
{
	long long n;
	scanf("%I64d", &n);
	printf("%I64d\n", (n + 1) % 2 + 1);
	return 0;
}
