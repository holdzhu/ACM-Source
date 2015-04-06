#include <cstdio>

const long long mod = 1000003;
long long inv[mod * 2 + 1];
long long f[mod * 2 + 1];
long long finv[mod * 2 + 1];

int main()
{
	inv[1] = 1;
	for (int i = 2; i <= mod * 2; ++i)
	{
		inv[i] = (mod - mod / i) * inv[mod % i] % mod;
	}
	f[0] = f[1] = 1;
	for (int i = 2; i <= mod * 2; ++i)
	{
		f[i] = f[i - 1] * i % mod;
	}
	finv[0] = finv[1] = 1;
	for (int i = 2; i <= mod * 2; ++i)
	{
		finv[i] = finv[i - 1] * inv[i] % mod;
	}
	int T;
	scanf("%d", &T);
	while (T--)
	{
		long long n, l, r;
		scanf("%lld %lld %lld", &n, &l, &r);
		long long d = r - l + 1;
		if ((n + d) / mod - n / mod > d / mod)
		{
			printf("%lld\n", mod - 1);
		}
		else
		{
			long long ans = 1;
			ans *= f[(n + d) % mod];
			ans %= mod;
			ans *= finv[n % mod];
			ans %= mod;
			ans *= finv[d % mod];
			ans %= mod;
			printf("%lld\n", (ans + mod - 1) % mod);
		}
	}
	return 0;
}
