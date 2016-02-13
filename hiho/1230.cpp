#include <cstdio>

const int mod = 1000000007;
const int inv2 = (mod + 1) / 2;
long long x[2048];

long long pow_mod(long long a, long long n)
{
	long long ret = 1;
	while (n)
	{
		if (n & 1)
		{
			ret = ret * a % mod;
		}
		a = a * a % mod;
		n >>= 1;
	}
	return ret;
}

void change(int l, int r)
{
	if (l != r)
	{
		int m = (l + r) / 2;
		change(l, m);
		change(m + 1, r);
		for (int i = 0; i < m - l + 1; ++i)
		{
			long long a = x[l + i], b = x[m + 1 + i];
			x[l + i] = (a + b) % mod;
			x[m + 1 + i] = (a - b + mod) % mod;
		}
	}
}

void inverse(int l, int r)
{
	if (l != r)
	{
		int m = (l + r) / 2;
		inverse(l, m);
		inverse(m + 1, r);
		for (int i = 0; i < m - l + 1; ++i)
		{
			long long a = x[l + i], b = x[m + 1 + i];
			x[l + i] = (a + b) * inv2 % mod;
			x[m + 1 + i] = (a - b + mod) * inv2 % mod;
		}
	}
}

int main()
{
	int n, m, L, R;
	int Log = 2048;
	while (scanf("%d %d %d %d", &n, &m, &L, &R) == 4)
	{
		long long ans = 0;
		for (int i = L; i <= R; ++i)
		{
			for (int j = 0; j < Log; ++j)
			{
				x[j] = (j >= i && j <= m + i);
			}
			change(0, Log - 1);
			for (int j = 0; j < Log; ++j)
			{
				x[j] = pow_mod(x[j], n * 2 + 1);
			}
			inverse(0, Log - 1);
			ans = (ans + x[0]) % mod;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
