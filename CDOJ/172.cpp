#include <cstdio>

int main()
{
	int a, b;
	while (scanf("%d %d", &a, &b) == 2 && a && b)
	{
		printf("%d\n", b / 3 - (a - 1) / 3);
	}
	return 0;
}
