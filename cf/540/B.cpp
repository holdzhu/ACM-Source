#include <cstdio>

int a[1000];

int main()
{
	int n, k, p, x, y;
	scanf("%d %d %d %d %d", &n, &k, &p, &x, &y);
	for (int i = 0; i < k; ++i)
	{
		scanf("%d", &a[i]);
	}
	int sum = 0;
	int less = 0;
	int large = 0;
	for (int i = 0; i < k; ++i)
	{
		if (a[i] < y)
		{
			less++;
		}
		else
		{
			large++;
		}
		sum += a[i];
	}
	if (less > n / 2)
	{
		printf("-1\n");
	}
	else
	{
		sum += (n / 2 - less) * 1 + (n - k - (n / 2 - less)) * y;
		if (sum <= x)
		{
			bool first = true;
			for (int i = 0; i < n / 2 - less; ++i)
			{
				if (first)
				{
					first = false;
				}
				else
				{
					printf(" ");
				}
				printf("%d", 1);
			}
			for (int i = 0; i < n - k - (n / 2 - less); ++i)
			{
				if (first)
				{
					first = false;
				}
				else
				{
					printf(" ");
				}
				printf("%d", y);
			}
			printf("\n");
		}
		else
		{
			printf("-1\n");
		}
	}
	return 0;
}
