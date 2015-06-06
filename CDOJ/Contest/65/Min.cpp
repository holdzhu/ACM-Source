#include <cstdio>

int main()
{
	printf("5000 5000\n");
	for (int i = 0; i < 4999; ++i)
	{
		printf("%d %d %d %d\n", i + 1, i + 2, 10, 10);
	}
	for (int i = 0; i < 5000; ++i)
	{
		printf("%d ", i + 1);
	}
	printf("\n");
	return 0;
}
