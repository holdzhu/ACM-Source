#include <cstdio>
#include <ctime>
#include <cstdlib>

int main()
{
	srand((int)time(0));
	printf("2000 10000000 10000000\n");
	for (int i = 0; i < 2000; ++i)
	{
		printf("%d ", rand() * rand() % 10000000);
	}
	return 0;
}
