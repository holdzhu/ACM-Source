#include <cstdio>

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	if (n == 1 || (n == 4 && m < 3))
	{
		puts("-1");
	}
	else if (n == 2)
	{
		printf("%d\n", m);
	}
	else if (n == 3)
	{
		printf("%d\n", m - 2);
	}
	else if (n == 4)
	{
		printf("%d\n", m - 3);
	}
	else if (m < (n - 1) >> 1)
	{
		puts("-1");
	}
	else
	{
		printf("%d\n", m - ((n - 1) >> 1));
	}
	return 0;
}
