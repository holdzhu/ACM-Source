#include <cstdio>

int main()
{
	int n, t, a, sgn = 1, sum, p, ta;
	while (scanf("%d %d", &n, &t) == 2 && n | t)
	{
		a = sum = 0;
		for (int i = -1; i < t; ++i)
		{
			for (ta = p = 0; n; ++p)
			{
				sum += n % 10;
				ta += n % 10 * (sgn = -sgn);
				n /= 10;
			}
			a += (p & 1 ? 1 : -1) * ta;
			n = sum;
		}
		puts(a % 11 ? "No" : "Yes");
	}
	return 0;
}
