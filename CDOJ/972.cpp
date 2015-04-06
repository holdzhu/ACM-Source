#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		if (n == 2)
		{
			printf("2=2\n");
		}
		else
		{
			bool f = true;
			printf("%d=", n);
			int p = 0;
			while (n % 2 == 0)
			{
				n /= 2;
				p++;
			}
			if (p > 1)
			{
				printf("2^%d", p);
				if (f)
				{
					f = false;
				}
				else
				{
					printf("*");
				}
			}
			else if (p == 1)
			{
				printf("2");
				if (f)
				{
					f = false;
				}
				else
				{
					printf("*");
				}
			}
			for (int i = 3; i * i <= n; i += 2)
			{
				p = 0;
				while (n % i == 0)
				{
					n /= i;
					p++;
				}
				if (p > 1)
				{
					if (f)
					{
						f = false;
					}
					else
					{
						printf("*");
					}
					printf("%d^%d", i, p);
				}
				else if (p == 1)
				{
					if (f)
					{
						f = false;
					}
					else
					{
						printf("*");
					}
					printf("%d", i);
				}
			}
			if (n > 1)
			{
				if (f)
				{
					f = false;
				}
				else
				{
					printf("*");
				}
				printf("%d", n);
			}
			else if (n == 1 && f)
			{
				printf("1");
			}
			printf("\n");
		}
	}
	return 0;
}
