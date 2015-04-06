#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		int a[n], b[n];
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &b[i]);
		}
		for (int i = 0; i < n; ++i)
		{
			if (a[i])
			{
				printf("(");
				int j = b[i];
				a[i] = 0;
				printf("%d", i + 1);
				while (j != i + 1)
				{
					printf(",%d", j);
					a[j - 1] = 0;
					j = b[j - 1];
				}
				printf(")");
			}
		}
		printf("\n");
	}
	return 0;
}
