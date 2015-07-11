#include <cstdio>
#include <cstring>

const long long mod = 10000007;

bool prime[2000001];
int mu[2000001];
int cnt[2000001];
int val[2000001];
int precalc[2000001];

void calcprime()
{
	memset(prime, true, sizeof prime);
	prime[1] = false;
	for (int i = 2; i < 10000; ++i)
	{
		if (prime[i]) for (int j = i * i; j <= 2000000; j += i)
		{
			prime[j] = false;
		}
	}
}

void calcmu()
{
	for (int i = 1; i <= 2000000; ++i)
	{
		mu[i] = 1;
	}
	for (int i = 2; i <= 2000000; ++i)
	{
		if (prime[i])
		{
			mu[i] = -1;
			for (int j = i * 2; j <= 2000000; j += i)
			{
				mu[j] *= -1;
			}
			if (i < 10000)
			{
				for (int j = i * i; j <= 2000000; j += i * i)
				{
					mu[j] = 0;
				}
			}
		}
	}
}

int powmod(long long a, int x)
{
	long long rnt = 1;
	while (x)
	{
		if (x & 1)
		{
			rnt *= a;
			rnt %= mod;
		}
		a *= a;
		a %= mod;
		x >>= 1;
	}
	return rnt;
}

int main()
{
	int t;
	calcprime();
	calcmu();
	long long tmp = 2;
	for (int i = 1; i <= 2000000; ++i)
	{
		precalc[i] = tmp - 1;
		if (precalc[i] < 0)
		{
			precalc[i] += mod;
		}
		tmp <<= 1;
		if (tmp >= mod)
		{
			tmp -= mod;
		}
	}
	scanf("%d", &t);
	while (t--)
	{
		int n, K;
		scanf("%d %d", &n, &K);
		memset(cnt, 0, sizeof cnt);
		int top = 0;
		while (n--)
		{
			int a;
			scanf("%d", &a);
			if (a > top)
			{
				top = a;
			}
			cnt[a]++;
		}
		for (int i = 1; i <= top; ++i)
		{
			val[i] = 0;
			for (int j = i; j <= top; j += i)
			{
				val[i] += cnt[j];
			}
			val[i] = precalc[val[i]];
		}
		long long ans = 0;
		for (int i = 1; i <= top; ++i)
		{
			long long sum = 0;
			for (int j = 1; i * j <= top; ++j)
			{
				sum += mu[j] * val[i * j];
				sum %= mod;
			}
			if (sum)
			{
				ans += sum * powmod(i, K);
				ans %= mod;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
