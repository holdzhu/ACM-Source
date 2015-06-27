#include <cstdio>

char s[100][101];
int a[100];
int sum[100];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", s[i]);
		sum[i] = 0;
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (s[i][j] == '1')
			{
				sum[j]++;
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		if (a[i] > 0)
		{
			printf("0\n\n");
			return 0;
		}
		if (sum[i] > 0)
		{
			for (int j = 0; j < n; ++j)
			{
				if (s[j][i] == '1')
				{
					printf("1\n%d\n", j + 1);
					return 0;
				}
			}
		}
	}
	printf("-1\n");
	return 0;
}
