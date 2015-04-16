#include <cstdio>

const long long mod = 1000000007;

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; ++t)
	{
		long long n;
		scanf("%lld", &n);
		printf("Case %d: ", t + 1);
		if (n % 2 == 0)
		{
			long long t = n / 2 % mod;
			long long p = (n + 1) % mod;
			long long q = (n - 3) % mod;
			printf("%lld\n", t * t % mod * p % mod * p % mod * (t * q % mod + 2) % mod);
		}
		else
		{
			long long t = n % mod;
			long long p = (n + 1) / 2 % mod;
			long long q = (n - 3) / 2 % mod;
			printf("%lld\n", t * t % mod * p % mod * p % mod * (t * q % mod + 2) % mod);
		}
	}
	return 0;
}
