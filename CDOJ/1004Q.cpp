#include <cstdio>
#include <cstdlib>
#include <ctime>

int main()
{
	srand((unsigned)time(NULL));
	int a[1001];
	for (int i = 0; i < 1001; ++i)
	{
		a[i] = (rand() % 2001) - 1000;
		printf("%d %d ", a[i], 1000 - i);
	}
	printf("-1 -1\n");
	for (int i = 0; i < 1001; ++i)
	{
		printf("+%d*x^%d", a[i], 1000 - i);
	}
	printf("\n");
	return 0;
}
