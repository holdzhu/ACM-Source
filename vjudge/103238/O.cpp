#include <cstdio>

const int mod = 1e9 + 9;
const int p = 691504013;
const int q = 308495997;
const int r = 276601605;

const int maxn = 100000;
long long fac[maxn + 1];
long long inv[maxn + 1];
long long facinv[maxn + 1];

long long pow_mod(long long a, long long k)
{
	long long s = 1;
	k %= mod - 1;
	while (k)
	{
		if (k & 1)
			s = s * a % mod;
		a = a * a % mod;
		k >>= 1;
	}
	return s;
}

int main()
{
	fac[0] = fac[1] = inv[1] = facinv[0] = facinv[1] = 1;
	for (int i = 2; i <= maxn; ++i)
	{
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = inv[mod % i] * (mod - mod / i) % mod;
		facinv[i] = facinv[i - 1] * inv[i] % mod;
	}
	int T;
	scanf("%d", &T);
	while (T--)
	{
		long long n;
		int k;
		scanf("%lld %d", &n, &k);
		long long t = pow_mod(p, k), ans = 0;
		for (int i = 0; i <= k; ++i)
		{
			ans = (ans + (i & 1 ? -1 : 1) * fac[k] * facinv[i] % mod * facinv[k - i] % mod * (t % mod == 1 ? n % mod : (pow_mod(t, n + 1) - t) * pow_mod(t - 1, mod - 2) % mod) % mod) % mod;
			t = t * (p - 1) % mod * q % mod;
		}
		printf("%lld\n", (ans + mod) * pow_mod(r, k) % mod);
	}
	return 0;
}
