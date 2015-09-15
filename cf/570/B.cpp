#include <cstdio>

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	if (n == 1)
	{
		printf("1\n");
	}
	else if (m * 2 <= n)
	{
		printf("%d\n", m + 1);
	}
	else
	{
		printf("%d\n", m - 1);
	}
	return 0;
}
