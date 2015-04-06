#include <cstdio>

int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		printf("%s\n", (n + 2) % 4? "no" : "yes");
	}
	return 0;
}
