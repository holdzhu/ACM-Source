#include <cstdio>

long long tri[100001];
long long fac[100001];
long long inv[100001];
long long facinv[100001];
const int mod = 1000000007;

long long C(int m, int n)
{
	return fac[m] * facinv[n] % mod * facinv[m - n] % mod;
}

int main()
{
	tri[0] = 1;
	for (int i = 1; i <= 100000; ++i)
	{
		tri[i] = tri[i - 1] * 3 % mod;
	}
	fac[0] = 1;
	for (int i = 1; i <= 100000; ++i)
	{
		fac[i] = fac[i - 1] * i % mod;
	}
	inv[1] = 1;
	for (int i = 2; i <= 100000; ++i)
	{
		inv[i] = inv[mod % i] * (mod - mod / i) % mod;
	}
	facinv[0] = facinv[1] = 1;
	for (int i = 2; i <= 100000; ++i)
	{
		facinv[i] = facinv[i - 1] * inv[i] % mod;
	}
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N;
		scanf("%d", &N);
		long long ans = tri[N];
		for (int i = 1; i <= N / 3; ++i)
		{
			ans -= C(N - i * 2, i) * tri[N - i * 3];
			ans %= mod;
		}
		if (ans < 0)
		{
			ans += mod;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
