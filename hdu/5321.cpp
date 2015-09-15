#include <cstdio>
#include <cstring>
#include <cmath>

const int N = 100000;
const int mod = 258280327;
bool prime[N + 1];
int mu[N + 1];
long long fac[N + 1];
long long pow2[N + 1];
long long inv[N + 1];
long long facinv[N + 1];
long long f1[N + 1];
long long f2[N + 1];
int c[100001];
int top;
int n;

void init()
{
	fac[0] = 1;
	for (int i = 1; i <= N; ++i)
	{
		fac[i] = fac[i - 1] * i % mod;
	}
	inv[0] = inv[1] = 1;
	for (int i = 2; i <= N; ++i)
	{
		inv[i] = inv[mod % i] * (mod - mod / i) % mod;
	}
	facinv[0] = 1;
	for (int i = 1; i <= N; ++i)
	{
		facinv[i] = facinv[i - 1] * inv[i] % mod;
	}
	pow2[0] = 1;
	for (int i = 1; i <= N; ++i)
	{
		pow2[i] = pow2[i - 1] * 2 % mod;
	}
	memset(prime, true, sizeof prime);
	prime[1] = false;
	for (int i = 2; i <= N; ++i)
	{
		if (prime[i])
		{
			if (i < 10000)
			{
				for (int j = i * i; j <= N; j += i)
				{
					prime[j] = false;
				}
			}
		}
	}
	for (int i = 2; i <= N; ++i)
	{
		mu[i] = 1;
	}
	mu[1] = 1;
	for (int i = 2; i <= N; ++i)
	{
		if (prime[i])
		{
			mu[i] = -1;
			for (int j = i * 2; j <= N; j += i)
			{
				mu[j] *= -1;
			}
			if (i < 10000)
			{
				for (int j = i * i; j <= N; j += i * i)
				{
					mu[j] = 0;
				}
			}
		}
	}
}

int main()
{
	init();
	while (scanf("%d", &n) == 1)
	{
		memset(f1, -1, sizeof f1);
		memset(f2, -1, sizeof f2);
		memset(c, 0, sizeof c);
		top = 0;
		for (int i = 0; i < n; ++i)
		{
			int t;
			scanf("%d", &t);
			for (int i = 1; i * i <= t; ++i)
			{
				if (t % i == 0)
				{
					c[i]++;
					if (i * i != t)
					{
						c[t / i]++;
					}
				}
			}
			if (t > top)
			{
				top = t;
			}
		}
		for (int i = 1; i <= top; ++i)
		{
			if (f1[c[i]] == -1)
			{
				int x = c[i];
				f1[x] = 0;
				for (int i = 1; i <= x; ++i)
				{
					f1[x] = f1[x] + fac[n + 1 - i] * facinv[x - i] % mod;
					if (f1[x] >= mod)
					{
						f1[x] -= mod;
					}
				}
				f1[x] = f1[x] * fac[x] % mod;
				f2[x] = x * (pow2[x - 1]) % mod;
			}
		}
		long long a = 0;
		long long b = 0;
		for (int i = 1; i <= top; ++i)
		{
			long long tmp1 = 0;
			long long tmp2 = 0;
			for (int j = 1; i * j <= top; ++j)
			{
				if (c[i * j] > 0)
				{
					tmp1 += mu[j] * f1[c[i * j]];
					if (tmp1 >= mod)
					{
						tmp1 -= mod;
					}
					else if (tmp1 < 0)
					{
						tmp1 += mod;
					}
					tmp2 += mu[j] * f2[c[i * j]];
					if (tmp2 >= mod)
					{
						tmp2 -= mod;
					}
					else if (tmp2 < 0)
					{
						tmp2 += mod;
					}
				}
			}
			a += tmp1 * i % mod;
			if (a >= mod)
			{
				a -= mod;
			}
			b += tmp2 * i % mod;
			if (b >= mod)
			{
				b -= mod;
			}
		}
		if (a > b)
		{
			printf("Mr. Zstu %I64d\n", a);
		}
		else if (a < b)
		{
			printf("Mr. Hdu %I64d\n", b);
		}
		else
		{
			printf("Equal %I64d\n", a);
		}
	}
	return 0;
}