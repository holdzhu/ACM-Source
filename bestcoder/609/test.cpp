#include <cstdio>


int main()
{
	printf("1 10000 10000\n");
	for (int i = 0; i < 5000; ++i)
	{
		printf("%d ", i);
	}
	for (int i = 0; i < 5000; ++i)
	{
		printf("%d ", i);
	}
	for (int i = 0; i < 10000; ++i)
	{
		printf("0 9999 ");
	}
	return 0;
}
