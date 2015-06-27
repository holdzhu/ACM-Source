#include <cstdio>

int main()
{
	printf("1000000000 1000000\n");
	for (int i = 0; i < 1000000; ++i)
	{
		printf("%d ", 1000 * i + 957);
	}
	printf("\n");
	return 0;
}
