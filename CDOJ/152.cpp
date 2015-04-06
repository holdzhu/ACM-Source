#include <cstdio>

int main()
{
	int N;
	scanf("%d", &N);
	double g = 0;
	int s = 0;
	while (N--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		s += a;
		if (b >= 90)
		{
			g += 4 * a;
		}
		else if (b >= 80)
		{
			g += 3 * a;
		}
		else if (b >= 70)
		{
			g += 2 * a;
		}
		else if (b >= 60)
		{
			g += a;
		}
	}
	printf("%.2lf\n", g / s);
	return 0;
}
