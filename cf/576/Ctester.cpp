#include <cstdio>

int main()
{
	printf("10000\n");
	for (int i = 0; i < 10000; ++i)
	{
		printf("%d %d\n", (i / 1000 % 2 == 0 ? i % 1000 : 999 - i % 1000) + 1000000 - 999, i / 1000);
	}
	return 0;
}
