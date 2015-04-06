#include <cstdio>

int main()
{
	int n;
	while (scanf("%d", &n) == 1 && n)
	{
		printf("%d\n", n * 8 - 4);
	}
	return 0;
}
