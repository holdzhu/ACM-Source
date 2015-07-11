#include <cstdio>

const int all = 360 * 12000;

int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		for (int h = 0; h < 12; ++h)
		{
			for (int m = 0; m < 60; ++m)
			{
				for (int s = 0; s < 6; ++s)
				{
					int hd = 30 * 12000 * h + 6000 * m + 1000 * s;
					int md = 6 * 12000 * m + 12000 * s;
					int dd = ((hd - md) % all + all) % all;
					if (dd > all / 2)
					{
						dd = all - dd;
					}
					if (dd == n)
					{
						printf("%02d:%02d:%02d\n", h, m, s * 10);
					}
				}
			}
		}
	}
	return 0;
}
