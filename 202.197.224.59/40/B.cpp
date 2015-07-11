#include <cstdio>

const int maxn = 387420489;
int pre[maxn / 100];

long long gcd(long long a, long long b, long long& x, long long& y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	long long g = gcd(b, a % b, y, x);
	y -= (a / b) * x;
	return g;
}

long long inv(long long a, long long m)
{
	long long x, y;
	gcd(a, m, x, y);
	return (x % m + m) % m;
}

long long pow(long long a, long long k, long long m)
{
	long long res = 1;
	a %= m;
	while (k)
	{
		if (k & 1)
		{
			res *= a;
			res %= m;
		}
		a *= a;
		k >>= 1;
	}
	return res;
}

long long fac(long long a, long long p, long long m, long long T)
{
	if (a == 0)
	{
		return 1;
	}
	int target = (a - 1) % m + 1;
	long long res = pre[target / 100];
	for (int i = 1; i <= target % 100; ++i)
	{
		if ((target / 100 * 100 + i) % 3)
		{
			res *= target / 100 * 100 + i;
			res %= m;
		}
	}
	res = res * pow(T, (a - 1) / m, m) % m;
	return res * fac(a / p, p, m, T) % m;
}

long long count(long long a, long long p)
{
	long long res = 0;
	while (a)
	{
		res += a / p;
		a /= p;
	}
	return res;
}

int main()
{
	int T;
	scanf("%d", &T);
	long long t = 1;
	for (int i = 0; i <= maxn; ++i)
	{
		if (i % 3 != 0)
		{
			t *= i;
			t %= maxn;
		}
		if (i % 100 == 0)
		{
			pre[i / 100] = t;
		}
	}
	while (T--)
	{
		long long n, m;
		int p;
		scanf("%lld %lld %d", &n, &m, &p);
		long long mod = pow(3, p, 1000000000000);
		int target = (mod - 1) % m + 1;
		long long res = pre[target / 100];
		for (int i = 1; i <= target % 100; ++i)
		{
			if ((target / 100 * 100 + i) % 3)
			{
				res *= target / 100 * 100 + i;
				res %= mod;
			}
		}
		long long ans = fac(n, 3, mod, res) * inv(fac(n - m, 3, mod, res), mod) % mod * inv(fac(m, 3, mod, res), mod) % mod *
						pow(3, count(n, 3) - count(n - m, 3) - count(m, 3), mod) % mod;
		printf("%lld\n", ans);
	}
	return 0;
}
