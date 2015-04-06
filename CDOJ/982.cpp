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
			while (n % 2 == 0)
			{
				n /= 2;
				if (f)
				{
					f = false;
				}
				else
				{
					printf("*");
				}
				printf("2");
			}
			for (int i = 3; i * i <= n; i += 2)
			{
				while (n % i == 0)
				{
					n /= i;
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
			printf("\n");
		}
	}
	return 0;
}
