#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		long long a, b, c, d;
		scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
		int n;
		long long w = a * c + b * d;
		if (w > 1000000)
		{
			n = 29;
		}
		else if (w > 500000)
		{
			n = 27;
		}
		else
		{
			n = 21;
		}
		if (b && a - b > n)
		{
			n = a - b;
		}
		printf("%d\n", n);
	}
	return 0;
}
