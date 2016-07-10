#include <cstdio>

const int mod = 10007;
const int inv2 = (mod + 1) / 2;
int C[11][11];

int pow_mod(int a, int k)
{
	int s = 1;
	while (k)
	{
		if (k & 1)
			s = s * a % mod;
		a = a * a % mod;
		k >>= 1;
	}
	return s;
}

int main()
{
	int m, n, t;
	scanf("%d %d %d", &m, &n, &t);
	for (int i = 0; i <= t; ++i)
	{
		C[i][0] = 1;
		for (int j = 1; j < i; ++j)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
		C[i][i] = 1;
	}
	int ans = 0;
	for (int i = 0; i <= t; ++i)
		ans = (ans + pow_mod(m - 2 * i, n) * C[t][i]) % mod;
	printf("%d\n", (ans * pow_mod(inv2, t) % mod + mod) % mod);
	return 0;
}
