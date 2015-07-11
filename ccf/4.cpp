#include <cstdio>

const long long mod = 1000000007;

long long fac[1000];

long long exgcd(long long a, long long b, long long& x, long long &y)
{
	if (b)
	{
		long long d = exgcd(b, a % b, y, x);
		y -= a / b * x;
		return d;
	}
	x = 1;
	y = 0;
	return a;
}

long long inv(long long a)
{
	long long x, y;
	exgcd(a, mod, x, y);
	return (x % mod + mod) % mod;
}

int main()
{
	int n;
	fac[0] = 1;
	for (int i = 1; i < 1000; ++i)
	{
		fac[i] = fac[i - 1] * i % mod;
	}
	scanf("%d", &n);
	long long ans = 0;
	for (int i = 2; i <= n - 2; ++i)
	{
		ans = (ans + (i - 1) * (n - i - 1) % mod * fac[n - 1] % mod * inv(fac[i - 1]) % mod * inv(fac[n - i]) % mod) % mod;
	}
	printf("%lld\n", ans);
	return 0;
}
