#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

const long long maxn = 3 * 1e18;
int mu[64];
int vis[2000001];
long long n;
int r;

bool isprime(int x)
{
	for (int i = 2; i < x; ++i)
	{
		if (x % i == 0)
		{
			return false;
		}
	}
	return true;
}

void init()
{
	for (int i = 2; i < 64; ++i)
	{
		mu[i] = 1;
	}
	for (int i = 2; i < 64; ++i)
	{
		if (isprime(i))
		{
			if (i <= r)
			{
				mu[i] = -1;
				for (int j = i * 2; j < 64; j += i)
				{
					mu[j] *= -1;
				}
				for (int j = i * i; j < 64; j += i * i)
				{
					mu[j] = 0;
				}
			}
			else
			{
				mu[i] = 0;
				for (int j = i * 2; j < 64; j += i)
				{
					mu[j] *= 0;
				}
				for (int j = i * i; j < 64; j += i * i)
				{
					mu[j] = 0;
				}
			}
		}
	}
}

bool check(long long x)
{
	long long cnt = 0;
	for (int i = 2; i <= r; ++i)
	{
		if (mu[i])
		{
			cnt -= (pow(x + 0.5, 1.0 / i) - 1) * mu[i];
		}
	}
	return x - cnt - 1 >= n;
}

bool check2(long long x)
{
	for (int i = 2; i < 64; ++i)
	{
		if (mu[i])
		{
			long long t = pow(x + 0.5, 1.0 / i);
			long long s = 1;
			for (int j = 0; j < i; ++j)
			{
				s *= t;
			}
			if (s == x)
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lld %d", &n, &r);
		init();
		long long l = n;
		long long r = n * 2 > maxn ? maxn : n * 2;
		while (l < r)
		{
			long long m = (l + r) >> 1;
			if (check(m))
			{
				r = m;
			}
			else
			{
				l = m + 1;
			}
		}
		for (; !check2(l); ++l);
		printf("%lld\n", l);
	}
	return 0;
}
