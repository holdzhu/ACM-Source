#include <cstdio>

int main()
{
	long long x;
	scanf("%I64d", &x);
	printf("%I64d\n", ((x % 360 + 405) % 360 - 1) / 90);
	return 0;
}
