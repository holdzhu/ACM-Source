#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int A, B, C;
		scanf("%d %d %d", &A, &B, &C);
		int a[A][B];
		int b[B][C];
		for (int i = 0; i < A; ++i)
		{
			for (int j = 0; j < B; ++j)
			{
				scanf("%d", &a[i][j]);
			}
		}
		for (int i = 0; i < B; ++i)
		{
			for (int j = 0; j < C; ++j)
			{
				scanf("%d", &b[i][j]);
			}
		}
		for (int i = 0; i < A; ++i)
		{
			for (int j = 0; j < C; ++j)
			{
				int s = 0;
				for (int k = 0; k < B; ++k)
				{
					s += a[i][k] * b[k][j];
				}
				printf("%d ", s);
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
