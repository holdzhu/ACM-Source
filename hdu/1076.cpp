#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int y, n;
		scanf("%d %d", &y, &n);
		for (int i = y; ; ++i)
		{
			if (i % 400 == 0 || (i % 100 > 0 && i % 4 == 0))
			{
				n--;
			}
			if (n == 0)
			{
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
}
