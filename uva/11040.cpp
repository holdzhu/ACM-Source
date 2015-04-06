#include <cstdio>

int main()
{
	int N;
	scanf("%d", &N);
	while (N--)
	{
		int a[9][9];
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j <= i; ++j)
			{
				scanf("%d", &a[i * 2][j * 2]);
			}
		}
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j <= i; ++j)
			{
				a[i * 2 + 2][j * 2 + 1] = (a[i * 2][j * 2] - a[i * 2 + 2][j * 2]-a[i * 2 + 2][j * 2 + 2]) / 2;
			}
		}
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < i * 2 + 2; ++j)
			{
				a[i * 2 + 1][j] = a[i * 2 + 2][j] + a[i * 2 + 2][j + 1];
			}
		}
		for (int i = 0; i < 9; ++i)
		{
			bool first = true;
			for (int j = 0; j <= i; ++j)
			{
				if (first)
				{
					first = false;
				}
				else
				{
					printf(" ");
				}
				printf("%d", a[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
