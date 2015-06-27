#include <cstdio>

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	int o = 0;
	int e = 0;
	for (int i = 0; i < n; ++i)
	{
		int t;
		scanf("%d", &t);
		if (t % 2 == 0)
		{
			e++;
		}
		else
		{
			o++;
		}
	}
	if (k == 0 || o == 0)
	{
		printf("Daenerys\n");
	}
	else if (k == n)
	{
		if (o % 2 == 1)
		{
			printf("Stannis\n");
		}
		else
		{
			printf("Daenerys\n");
		}
	}
	else if ((n - k) % 2 == 0)
	{
		if (e == 0)
		{
			if (k % 2 == 1)
			{
				printf("Stannis\n");
			}
			else
			{
				printf("Daenerys\n");
			}
		}
		else
		{
			int ss = (n - k) / 2;
			if (e <= ss && k % 2 == 1)
			{
				printf("Stannis\n");
			}
			else
			{
				printf("Daenerys\n");
			}
		}
	}
	else
	{
		if (e == 0)
		{
			if (k % 2 == 1)
			{
				printf("Stannis\n");
			}
			else
			{
				printf("Daenerys\n");
			}
		}
		else
		{
			int ds = (n - k) / 2;
			if (e <= ds && k % 2 == 0)
			{
				printf("Daenerys\n");
			}
			else if (o <= ds)
			{
				printf("Daenerys\n");
			}
			else
			{
				printf("Stannis\n");
			}
		}
	}
	return 0;
}
