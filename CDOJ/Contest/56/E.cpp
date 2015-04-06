#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		printf("Case #%d: ", kase);
		if (x == 0)
		{
			printf("1\n");
		}
		else
		{
			if (x + 2 * y >= 4)
			{
				printf("%d\n", x + 2 * y + 5 * z + 1);
			}
			else
			{
				printf("%d\n", x + 2 * y + 1);
			}
		}
	}
	return 0;
}
