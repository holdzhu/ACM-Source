#include <cstdio>
#include <cstring>
#include <cmath>

const int maxn = 2000000;
const int maxnsqr = sqrt(maxn + 0.5);
const int mod = 1000000007;

int K;
bool prime[maxn + 1];
int mu[maxn + 1];
long long g[maxn + 1];

void calcprime()
{
	memset(prime, true, sizeof prime);
	prime[1] = false;
	for (int i = 2; i < maxnsqr; ++i)
	{
		if (prime[i]) for (int j = i * i; j <= maxn; j += i)
		{
			prime[j] = false;
		}
	}
}

void calcmu()
{
	for (int i = 1; i <= maxn; ++i)
	{
		mu[i] = 1;
	}
	for (int i = 2; i <= maxn; ++i)
	{
		if (prime[i])
		{
			mu[i] = -1;
			for (int j = i * 2; j <= maxn; j += i)
			{
				mu[j] *= -1;
			}
			if (i < maxnsqr)
			{
				for (int j = i * i; j <= maxn; j += i * i)
				{
					mu[j] = 0;
				}
			}
		}
	}
}

int getMu(long long x, int low = 2)
{
	if (x <= maxn)
	{
		return mu[x];
	}
	int sqr = sqrt(x + 0.5);
	for (int i = low; i <= sqr; ++i)
	{
		if (x % i == 0)
		{
			if (x / i % i == 0)
			{
				return 0;
			}
			return getMu(x / i, i + 1) * -1;
		}
	}
	return -1;
}

long long powmod(long long x, int k)
{
	long long rnt = 1;
	for (int i = 0; i < k; ++i)
	{
		rnt *= x;
		rnt %= mod;
	}
	return rnt;
}

int getG(long long x, int low = 2)
{
	if (x <= maxn && g[x] != -1)
	{
		return g[x];
	}
	printf("%lld\n", x);
	long long ans = -1;
	int sqr = sqrt(x + 0.5);
	for (int i = low; i <= sqr; ++i)
	{
		if (x % i == 0)
		{
			if (x / i % i == 0)
			{
				ans = getMu(x / i, i) * powmod(i, K);
			}
			else
			{
				ans = getMu(x / i, i) * powmod(i, K) - getG(x / i, i);
			}
			break;
		}
	}
	if (ans == -1)
	{
		ans = powmod(x, K) - 1;
	}
	if (x <= maxn)
	{
		g[x] = ans;
	}
	return ans;
}

int main()
{
	calcprime();
	calcmu();
	memset(g, -1, sizeof g);
	g[1] = 1;
	long long N;
	scanf("%lld %d", &N, &K);
	long long ans = 0;
	for (int i = 1; i <= N; ++i)
	{
		ans += N / i * N / i % mod * getG(i) % mod;
		ans %= mod;
	}
	printf("%lld\n", ans);
	return 0;
}
