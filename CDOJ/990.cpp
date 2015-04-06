#include <cstdio>
#include <cmath>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a > b + c || b > a + c || c > a + b)
		{
			printf("(%d,%d,%d) can't construct a triangle!\n", a, b, c);
		}
		else
		{
			double p = (a + b + c) / 2.0;
			double s = sqrt(p * (p - a) * (p - b) * (p - c));
			printf("S(%d,%d,%d)=%.2lf\n", a, b, c, s);
		}
	}
	return 0;
}
