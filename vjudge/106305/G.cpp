#include <cstdio>

const int mod = 1000003;

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

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
	int n;
	scanf("%d", &n);
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		ans = (ans + 1ll * pow_mod(2, gcd(i, n)) % mod) % mod;
	printf("%lld\n", (pow_mod(2, n) - 1ll * ans * pow_mod(n, mod - 2) % mod + mod) % mod);
	return 0;
}
