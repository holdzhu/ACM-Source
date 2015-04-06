#include <cstdio>

int main()
{
	double d;
	while (scanf("%lf", &d) == 1 && d > 0)
	{
		for (int i = 2; ; ++i)
		{
			if (d <= 0)
			{
				printf("%d card(s)\n", i - 2);
				break;
			}
			d -= 1.0 / i;
		}
	}
	return 0;
}
