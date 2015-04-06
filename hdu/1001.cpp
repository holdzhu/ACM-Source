#include <cstdio>

int main()
{
	long long n;
	while (scanf("%lld", &n) == 1)
	{
		printf("%lld\n\n", n * (n + 1) / 2);
	}
	return 0;
}
