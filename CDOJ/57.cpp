#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int a[3][3];
		int b[3][3];
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				scanf("%d", &a[i][j]);
			}
		}
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				scanf("%d", &b[i][j]);
			}
		}
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				int s = 0;
				for (int k = 0; k < 3; ++k)
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
