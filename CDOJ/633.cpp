#include <cstdio>

int main()
{
	int M;
	while (scanf("%d", &M) == 1)
	{
		printf("%lld\n", (3LL * M * M + 5 * M + 3) / 2);
	}
	return 0;
}
