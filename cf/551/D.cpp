#include <cstdio>

long long n, k;
long long l, m;

long long fib(long long x)
{
	x++;
	long long a[2][2];
	a[0][0] = a[1][1] = 1;
	a[0][1] = a[1][0] = 0;
	long long b[2][2];
	b[0][0] = b[0][1] = b[1][0] = 1;
	b[1][1] = 0;
	long long tmp[2][2];
	while (x)
	{
		if (x & 1)
		{
			for (int i = 0; i < 2; ++i)
			{
				for (int j = 0; j < 2; ++j)
				{
					tmp[i][j] = 0;
					for (int k = 0; k < 2; ++k)
					{
						tmp[i][j] += a[i][k] * b[k][j] % m;
					}
				}
			}
			for (int i = 0; i < 2; ++i)
			{
				for (int j = 0; j < 2; ++j)
				{
					a[i][j] = tmp[i][j] % m;
				}
			}
		}
		x >>= 1;
		for (int i = 0; i < 2; ++i)
		{
			for (int j = 0; j < 2; ++j)
			{
				tmp[i][j] = 0;
				for (int k = 0; k < 2; ++k)
				{
					tmp[i][j] += b[i][k] * b[k][j] % m;
				}
			}
		}
		for (int i = 0; i < 2; ++i)
		{
			for (int j = 0; j < 2; ++j)
			{
				b[i][j] = tmp[i][j] % m;
			}
		}
	}
	return a[0][0];
}

long long powmod(long long n, long long p)
{
	long long rnt = 1;
	long long s = n;
	while (p)
	{
		if (p & 1)
		{
			rnt *= s;
			rnt %= m;
		}
		p >>= 1;
		s *= s;
		s %= m;
	}
	return rnt;
}

int main()
{
	scanf("%I64d %I64d %I64d %I64d", &n, &k, &l, &m);
	long long ans = 1 % m;
	long long zero = fib(n);
	long long one = powmod(2, n) - zero;
	if (one < 0)
	{
		one += m;
	}
	for (int i = 0; i < l; ++i)
	{
		if (k & 1)
		{
			ans *= one;
		}
		else
		{
			ans *= zero;
		}
		ans %= m;
		k >>= 1;
	}
	if (k)
	{
		printf("0\n");
	}
	else
	{
		printf("%I64d\n", ans);
	}
	return 0;
}
