#include <cstdio>

int main()
{
	int n, T;
	scanf("%d %d", &n, &T);
	while (T--)
	{
		int m;
		scanf("%d", &m);
		for (int i = 0; i < m % n; ++i)
		{
			printf("%d ", n - m % n + i + 1);
		}
		for (int i = m % n; i < n; ++i)
		{
			printf("%d ", i - m % n + 1);
		}
		printf("\n");
	}
	return 0;
}
