#include <cstdio>

const int mod = 1e9 + 7;
const int maxn = 1e5;

long long fac[maxn + 1];
long long inv[maxn + 1];
long long facinv[maxn + 1];

long long C(int n, int m)
{
	if (n < 0 || m < 0 || m > n)
		return 0;
	return fac[n] * facinv[m] % mod * facinv[n - m] % mod;
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
		int N, K;
		scanf("%d %d", &N, &K);
		int cnt = 0;
		for (int i = 0; i < N; ++i)
		{
			int A;
			scanf("%d", &A);
			cnt += (bool)A;
		}
		long long ans = 0;
		if (cnt == N)
		{
			for (int i = K; i >= 0; i -= 2)
			{
				if (i > N)
					continue;
				ans = (ans + C(N, i)) % mod;
			}
		}
		else
		{
			for (int i = K; i >= 0; --i)
			{
				if (i > cnt)
					continue;
				ans = (ans + C(cnt, i)) % mod;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
