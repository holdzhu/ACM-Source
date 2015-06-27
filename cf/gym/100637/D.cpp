#include <cstdio>
#include <cmath>

long long exgcd(long long a, long long b, long long &x, long long &y)
{
	if (!b)
	{
		x = 1;
		y = 0;
		return a;
	}
	long long d = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return d;
}

int inv(long long a, int mod)
{
	long long x, y;
	exgcd(a, mod, x, y);
	return (x % mod + mod) % mod;
}

int pow(long long a, long long k, int mod)
{
	long long res = 1;
	long long s = a;
	while (k)
	{
		if (k & 1)
		{
			res = res * s % mod;
		}
		s = s * s % mod;
		k >>= 1;
	}
	return res;
}

int fac(long long n, int prime, int mod)
{
	if (!n)
	{
		return 1;
	}
	long long res;
	long long prod = 1;
	for (long long i = 1; i <= mod; ++i)
	{
		if (i % prime)
		{
			prod = prod * i % mod;
		}
		if (i == (n - 1) % mod + 1)
		{
			res = prod;
		}
	}
	res = res * pow(prod, (n - 1) / mod, mod) % mod;
	return res * fac(n / prime, prime, mod) % mod;
}

int count(long long n, int p)
{
	long long res = 0;
	while (n)
	{
		res += n / p;
		n /= p;
	}
	return res;
}

long long solve(long long n, long long k, int m, int prime, int mod)
{
	long long res = 1;
	res = res * fac(n, prime, mod) % mod * inv(fac(k, prime, mod), mod) % mod * inv(fac(n - k, prime, mod), mod) % mod;
	res = res * pow(prime, count(n, prime) - count(k, prime) - count(n - k, prime), mod) % mod;
	return res * (m / mod) % m * inv(m / mod, mod) % m;
}

int main()
{
	long long n, k;
	long long m;
	scanf("%I64d %I64d %I64d", &n, &k, &m);
	long long sqr = sqrt(m + 0.5);
	long long t = m;
	long long ans = 0;
	for (long long i = 2; t > 1; ++i)
	{
		long long mod = 1;
		if (i > sqr)
		{
			mod = t;
			i = t;
			t = 1;
		}
		else while (t % i == 0)
		{
			t /= i;
			mod *= i;
		}
		if (mod > 1)
		{
			ans = (ans + solve(n, k, m, i, mod)) % m;
		}
	}
	printf("%I64d\n", ans);
	return 0;
}