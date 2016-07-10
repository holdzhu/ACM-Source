#include <cstdio>
#include <algorithm>

using namespace std;

const int mod = 1e9 + 7;

long long solve(long long x)
{
	if (x & 1)
		return (x + 1) / 2 % mod * (x % mod) % mod;
	return x / 2 % mod * ((x + 1) % mod) % mod;
}

int main()
{
	long long n, m;
	scanf("%I64d %I64d", &n, &m);
	long long sum = 0;
	for (int i = 1; 1ll * i * i <= n && i <= m; ++i)
	{
		if (n / i != i)
			sum = (sum + n / i * i) % mod;
		sum = (sum + i * (solve(min(n / i, m)) - solve(min(n / (i + 1), m))) % mod) % mod;
	}
	printf("%I64d\n", (((n % mod) * (m % mod) % mod - sum) % mod + mod) % mod);
	return 0;
}
