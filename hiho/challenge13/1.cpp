#include <cstdio>
#include <cstdlib>

const int mod = 1000000007;
int n, m, x, y;
long long fac[201];
long long inv[201];
long long facinv[201];

long long C(int a, int b)
{
	return fac[a] * facinv[b] % mod * facinv[a - b] % mod;
}

long long solve(int x, int y)
{
	return C(x + y, x);
}

void init()
{
	fac[0] = 1;
	for (int i = 1; i <= 200; ++i)
	{
		fac[i] = fac[i - 1] * i % mod;
	}
	inv[0] = inv[1] = 1;
	for (int i = 2; i <= 200; ++i)
	{
		inv[i] = inv[mod % i] * (mod - mod / i) % mod;
	}
	facinv[0] = 1;
	for (int i = 1; i <= 200; ++i)
	{
		facinv[i] = facinv[i - 1] * inv[i] % mod;
	}
}

int main()
{
	init();
	while (scanf("%d %d %d %d", &n, &m, &x, &y) == 4)
	{
		long long ans = 0;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				if (i == 1 || j == 1 || i == n || j == m)
				{
					ans += solve(abs(x - i), abs(y - j));
					ans %= mod;
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
