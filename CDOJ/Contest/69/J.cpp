#include <cstdio>
#include <cstring>
#include <cmath>

const int mod = 1000000007;
bool primes[1000001];

int f(int n, int p)
{
	return n % p == 0 ? f(n / p, p) : log(n) / log(p);
}

int powmod(int n, int p)
{
	long long rnt = 1;
	long long s = n;
	while (p)
	{
		if (p & 1)
		{
			rnt *= s;
			rnt %= mod;
		}
		p >>= 1;
		s *= s;
		s %= mod;
	}
	return rnt;
}

int main()
{
	int n;
	scanf("%d", &n);
	int sqr = sqrt(n + 0.5);
	memset(primes, true, sizeof primes);
	long long l = powmod(2, f(n + 1, 2));
	for (int i = 3; i <= n; i += 2)
	{
		if (primes[i])
		{
			if (i <= sqr)
			{
				for (int j = i * i; j <= n; j += i * 2)
				{
					primes[j] = false;
				}
			}
			l *= powmod(i, f(n + 1, i));
			l %= mod;
		}
	}
	printf("%lld\n", l);
	return 0;
}
