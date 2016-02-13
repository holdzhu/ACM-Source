#include <cstdio>

const int mod = 1e9 + 7;
const int maxn = 2e5;
long long fac[maxn + 1];
long long inv[maxn + 1];
long long facinv[maxn + 1];
long long phi[maxn + 1];

long long C(long long n, long long m)
{
	if (n < 0 || m < 0 || m > n)
		return 0;
	return fac[n] * facinv[m] % mod * facinv[n - m] % mod;
}

long long solve(int n, int m, int k)
{
	return C(n - 1ll * m * k + m - 1, m - 1) * n % mod * inv[m] % mod;
}

int main()
{
	fac[0] = fac[1] = inv[0] = inv[1] = facinv[0] = facinv[1] = 1;
	for (int i = 2; i <= maxn; ++i)
	{
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = inv[mod % i] * (mod - mod / i) % mod;
		facinv[i] = facinv[i - 1] * inv[i] % mod;
	}
	phi[1] = 1;
	for (int i = 2; i <= maxn; ++i) if (!phi[i])
		for (int j = i; j <= maxn; j += i)
		{
			if (!phi[j])
				phi[j] = j;
			phi[j] = phi[j] / i * (i - 1);
		}
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		int n, m, k;
		scanf("%d %d %d", &n, &m, &k);
		long long ans = 0;
		if (m > 1)
		{
			for (int i = 1; i * i <= n; ++i)
			{
				if (n % i == 0)
				{
					ans = (ans + phi[n / i] * (m % (n / i) == 0 ? solve(i, m / (n / i), k) : 0) % mod) % mod;
					if (i * i != n)
						ans = (ans + phi[i] * (m % i == 0 ? solve(n / i, m / i, k) : 0) % mod) % mod;
				}
			}
			ans = ans * inv[n] % mod;
		}
		else
		{
			ans = 1;
		}
		printf("Case #%d: %I64d\n", kase, ans);
	}
	return 0;
}
