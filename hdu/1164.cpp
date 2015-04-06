#include <cstdio>

int main()
{
	int x;
	while (scanf("%d", &x) == 1)
	{
		bool first = true;
		for (int i = 2; i < 65536; ++i)
		{
			while (x % i == 0)
			{
				x /= i;
				if (first)
				{
					first = false;
				}
				else
				{
					printf("*");
				}
				printf("%d", i);
			}
		}
		printf("\n");
	}
	return 0;
}
