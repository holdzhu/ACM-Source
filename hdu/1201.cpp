#include <cstdio>

bool isleap(int y)
{
	return y % 400 == 0 || (y % 100 != 0 && y % 4 == 0);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int y, m, d;
		scanf("%d-%d-%d", &y, &m, &d);
		if (m == 2 && d == 29)
		{
			printf("-1\n");
		}
		else
		{
			int c = 0;
			for (int i = y + 1; i < y + 18; ++i)
			{
				if (isleap(i))
				{
					c++;
				}
			}
			if (m <= 2 && isleap(y))
			{
				c++;
			}
			if (m > 2 && isleap(y + 18))
			{
				c++;
			}
			printf("%d\n", 365 * 18 + c);
		}
	}
	return 0;
}
