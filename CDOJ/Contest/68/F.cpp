#include <cstdio>
#include <cmath>

const long long mod = 1000000007;

long long powmod(long long x, long long n)
{
	if (x == 0)
	{
		return 0;
	}
	if (n == 0)
	{
		return 1;
	}
	long long g = powmod(x, n / 2) % mod;
	g *= g;
	g %= mod;
	if (n % 2 == 1)
	{
		g *= x;
		g %= mod;
	}
	return g % mod;
}

long long powm(long long x, long long n)
{
	if (x == 0)
	{
		return 0;
	}
	long long g = 1;
	for (int i = 0; i < n; ++i)
	{
		g *= x;
		g %= mod;
	}
	return g % mod;
}

int main()
{
	long long k, d, n;
	scanf("%lld %lld %lld", &k, &d, &n);
	if (n % d == 0)
	{
		n /= d;
		long long t = n;
		long long sq = sqrt(n + 0.5);
		long long ans = 1;
		for (int i = 2; i <= sq && i <= n && t > 1; ++i)
		{ 
			long long c = 0;
			while (t % i == 0)
			{
				c++;
				t /= i;
			}
			if (c)
			{
				long long po = ((powmod(c + 1, k) - 2 * powmod(c, k)) % mod + powmod(c - 1, k)) % mod;
				if (po < 0)
				{
					po += mod;
				}
				ans *= po;
				ans %= mod;
			}
		}
		if (t > 1)
		{
			long long po = ((powmod(2, k) - 2 * powmod(1, k)) % mod + powmod(0, k)) % mod;
			if (po < 0)
			{
				po += mod;
			}
			ans *= po;
			ans %= mod;
		}
		ans %= mod;
		if (ans < 0)
		{
			ans += mod;
		}
		printf("%lld\n", ans);
	}
	else
	{
		printf("0\n");
	}
	return 0;
}
