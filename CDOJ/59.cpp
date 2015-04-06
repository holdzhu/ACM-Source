#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);
	getchar();
	while (n--)
	{
		char c;
		int num = 0;
		bool isget = false;
		while ((c = getchar()) != '\n')
		{
			if (c >= '0' && c <= '9')
			{
				num *= 10;
				num += c - '0';
				isget = true;
			}
			else
			{
				if (isget)
				{
					printf("%d ", num);
					num = 0;
					isget = false;
				}
			}
		}
		if (isget)
		{
			printf("%d ", num);
			num = 0;
			isget = false;
		}
		printf("\n");
	}
	return 0;
}
