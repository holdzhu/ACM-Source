#include <cstdio>

int main()
{
	int a;
	while (scanf("%d", &a) == 1 && a != 42)
	{
		printf("%d\n", a);
	}
	return 0;
}
