#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		if (n <= 9)
		{
			printf("%d\n", n);
		}
		else
		{
			n -= 9;
			if (n <= 180)
			{
				if (n % 2 == 0)
				{
					printf("%d\n", 9 + n / 2);
				}
				else
				{
					printf("-1\n");
				}
			}
			else
			{
				n -= 180;
				if (n % 3 == 0)
				{
					printf("%d\n", 99 + n / 3);
				}
				else
				{
					printf("-1\n");
				}
			}
		}
	}
	return 0;
}
