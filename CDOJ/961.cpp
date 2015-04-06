#include <cstdio>

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	if (n == m % n * 2)
	{
		for (int i = 0; i < m % n; ++i)
		{
			printf("(%d,%d) ", i + 1, (i + m) % n + 1);
		}
		printf("\n");
	}
	else if (m % n == 0)
	{
		printf("\n");
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			printf("(%d,%d) ", i + 1, (i + m) % n + 1);
		}
		printf("\n");
	}
	return 0;
}
