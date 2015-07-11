#include <cstdio>
#include <cstring>

const int mod = 1000000007;
int a, b, c, n;
int tmp[5000];
long long dp[2][5001];
long long fac[5001];
long long inv[5001];
long long facinv[5001];

int powmod(int n, int p)
{
	long long rnt = 1;
	long long s = n;
	while (p)
	{
		if (p & 1)
		{
			rnt *= s;
			rnt %= mod;
		}
		p >>= 1;
		s *= s;
		s %= mod;
	}
	return rnt;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &tmp[i]);
	}
	a = b = c = 0;
	for (int i = 0; i < n; ++i)
	{
		int t;
		scanf("%d", &t);
		if (tmp[i])
		{
			if (t)
			{
				b++;
			}
			else
			{
				a++;
			}
		}
		else if (t)
		{
			c++;
		}
	}
	if (a + b < n - a - b)
	{
		printf("0\n");
		return 0;
	}
	int cur = 0;
	memset(dp, 0, sizeof dp);
	for (int i = 1; i <= a + b; ++i)
	{
		cur = !cur;
		dp[cur][0] = 1;
		for (int j = 1; j <= b; ++j)
		{
			dp[cur][j] = (dp[!cur][j] + (i - j) * dp[!cur][j - 1]) % mod;
		}
	}
	inv[1] = 1;
	fac[0] = fac[1] = 1;
	facinv[0] = facinv[1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		inv[i] = inv[mod % i] * (mod - mod / i) % mod;
		fac[i] = fac[i - 1] * i % mod;
		facinv[i] = facinv[i - 1] * inv[i] % mod;
	}
	printf("%lld\n", dp[cur][b] * fac[a] % mod * facinv[c] % mod * facinv[a - c] % mod * powmod(n - 1, a - c) % mod * fac[a] % mod * fac[b] % mod * fac[c] % mod);
	return 0;
}
