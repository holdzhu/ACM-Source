#include <cstdio>

const int mod = 1e9 + 7;

int main()
{
	int n;
	scanf("%d", &n);
	long long ans = 1;
	long long ans2 = 1;
	for (int i = 0; i < n; ++i)
	{
		ans *= 27;
		ans %= mod;
		ans2 *= 7;
		ans2 %= mod;
	}
	printf("%I64d\n", ((ans - ans2) % mod + mod) % mod);
	return 0;
}
