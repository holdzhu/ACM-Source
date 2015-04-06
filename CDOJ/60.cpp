#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);
	getchar();
	while (n--)
	{
		char c;
		int l = 0;
		int num = 0;
		while ((c = getchar()) != '\n')
		{
			if (c == ' ')
			{
				if (l)
				{
					num++;
					l = 0;
				}
			}
			else
			{
				l++;
			}
		}
		if (l)
		{
			num++;
		}
		printf("%d\n", num);
	}
	return 0;
}
