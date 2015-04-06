#include <cstdio>
#include <cstdlib>

int A, B, C;

int ** mul(int ** a, int ** b)
{
	int ** S = (int **) malloc(sizeof(int *) * A);
	for (int i = 0; i < A; ++i)
	{
		S[i] = (int *) malloc(sizeof(int) * C);
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
			S[i][j] = s;
		}
	}
	return S;
}

int main()
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d %d %d", &A, &B, &C);
		int **a = (int **) malloc(sizeof(int *) * A);
		for (int i = 0; i < A; ++i)
		{
			a[i] = (int *) malloc(sizeof(int) * B);
		}
		int **b = (int **) malloc(sizeof(int *) * B);
		for (int i = 0; i < B; ++i)
		{
			b[i] = (int *) malloc(sizeof(int) * C);
		}
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
		int ** S = mul(a, b);
		for (int i = 0; i < A; ++i)
		{
			for (int j = 0; j < C; ++j)
			{
				printf("%d ", S[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
