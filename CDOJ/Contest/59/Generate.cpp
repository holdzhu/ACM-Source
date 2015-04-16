#include <cstdio>
#include <cstdlib>

int main()
{
	printf("250000\n");
	for (int i = 0; i < 250000; ++i)
	{
		printf("%d\n", 250000 - i);
	}
	return 0;
}
