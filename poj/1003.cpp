#include <cstdio>

int main()
{
	double c;
	while (scanf("%lf", &c) && c > 0)
	{
		int a = 1;
		for (int i = 2; ; ++i)
		{
			if (c >= 1.0 / i)
			{
				c -= 1.0 / i;
				a++;
			}
			else
			{
				break;
			}
		}
		printf("%d card(s)\n", a);
	}
	return 0;
}
