#include <cstdio>

const int mod = 1e9 + 7;
const int maxk = 1e6;
int inv[maxk + 2];
int facinv[maxk + 2];
int f[maxk + 2];
int pre[maxk + 2];
int suf[maxk + 2];

int pow_mod(int a, int k)
{
	int s = 1;
	while (k)
	{
		if (k & 1)
			s = 1ll * s * a % mod;
		a = 1ll * a * a % mod;
		k >>= 1;
	}
	return s;
}

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= k + 1; ++i)
	{
		f[i] = f[i - 1] + pow_mod(i, k);
		if (f[i] >= mod)
			f[i] -= mod;
	}
	inv[1] = facinv[0] = facinv[1] = 1;
	for (int i = 2; i <= k + 1; ++i)
	{
		inv[i] = 1ll * inv[mod % i] * (mod - mod / i) % mod;
		facinv[i] = 1ll * facinv[i - 1] * inv[i] % mod;
	}
	pre[0] = 1;
	for (int i = 1; i <= k + 1; ++i)
		pre[i] = 1ll * pre[i - 1] * (n - i + 1) % mod;
	suf[k + 1] = 1;
	for (int i = k; i >= 0; --i)
		suf[i] = 1ll * suf[i + 1] * (n - i - 1) % mod;
	int ans = 0;
	for (int i = 0; i <= k + 1; ++i)
	{
		if ((k + i) & 1)
			ans = ans
				  + 1ll * pre[i] * suf[i] % mod * facinv[i] % mod
						* facinv[k + 1 - i] % mod * f[i] % mod;
		else
			ans = ans + mod
				  - 1ll * pre[i] * suf[i] % mod * facinv[i] % mod
						* facinv[k + 1 - i] % mod * f[i] % mod;
		if (ans >= mod)
			ans -= mod;
	}
	printf("%d\n", ans);
	return 0;
}
