#include <cstdio>

int main()
{
	int k;
	scanf("%d", &k);
	if (k % 2 == 0)
	{
		printf("NO\n");
	}
	else
	{
		printf("YES\n");
		int n = k * k + 1;
		int m = n * k / 2;
		printf("%d %d\n", n, m);
		printf("1 2\n");
		int cnt = 3;
		for (int i = 0; i < k / 2; ++i)
		{
			printf("1 %d\n", cnt);
			printf("1 %d\n", cnt + 1);
			for (int j = 0; j < k - 1; ++j)
			{
				printf("%d %d\n", cnt, cnt + 2 + j);
				printf("%d %d\n", cnt + 1, cnt + 2 + j);
			}
			for (int j = 0; j < k - 1; ++j)
			{
				for (int l = j + 1; l < k - 1; ++l)
				{
					printf("%d %d\n", cnt + 2 + j, cnt + 2 + l);
				}
			}
			cnt += k + 1;
		}
		for (int i = 0; i < k / 2; ++i)
		{
			printf("2 %d\n", cnt);
			printf("2 %d\n", cnt + 1);
			for (int j = 0; j < k - 1; ++j)
			{
				printf("%d %d\n", cnt, cnt + 2 + j);
				printf("%d %d\n", cnt + 1, cnt + 2 + j);
			}
			for (int j = 0; j < k - 1; ++j)
			{
				for (int l = j + 1; l < k - 1; ++l)
				{
					printf("%d %d\n", cnt + 2 + j, cnt + 2 + l);
				}
			}
			cnt += k + 1;
		}
	}
	return 0;
}
