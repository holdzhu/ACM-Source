#include <cstdio>

int main()
{
	int n, t;
	scanf("%d %d", &n, &t);
	if (t < 10)
	{
		for (int i = 0; i < n; ++i)
		{
			printf("%d", t);
		}
		puts("");
	}
	else
	{
		if (n == 1)
		{
			printf("-1\n");
			return 0;
		}
		printf("1");
		for (int i = 0; i < n - 1; ++i)
		{
			printf("0");
		}
		puts("");
	}
	return 0;
}
