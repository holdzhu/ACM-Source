#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a > b)
		{
			int t = b;
			b = a;
			a = t;
		}
		if (b > c)
		{
			int t = b;
			b = c;
			c = t;
		}
		if (a > b)
		{
			int t = b;
			b = a;
			a = t;
		}
		if (a == b)
		{
			printf("%d\n", c);
		}
		else
		{
			printf("%d\n", b);
		}
	}
	return 0;
}
