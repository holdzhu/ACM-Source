#include <cstdio>

const int mod = 880803841;

long long pow_mod(long long a, long long k)
{
	long long s = 1;
	while (k)
	{
		if (k & 1)
			s = s * a % mod;
		a = a * a % mod;
		k >>= 1;
	}
	return s;
}

bool solve(int n)
{
	for (int i = 0; i <= 23; ++i)
	{
		int s = 1 << i;
		if (i != 23 && pow_mod(n, s * 3 * 5 * 7) == 1) return false;
		if (pow_mod(n, s * 3 * 5 * 1) == 1) return false;
		if (pow_mod(n, s * 3 * 1 * 7) == 1) return false;
		if (pow_mod(n, s * 3 * 1 * 1) == 1) return false;
		if (pow_mod(n, s * 1 * 5 * 7) == 1) return false;
		if (pow_mod(n, s * 1 * 5 * 1) == 1) return false;
		if (pow_mod(n, s * 1 * 1 * 7) == 1) return false;
		if (pow_mod(n, s * 1 * 1 * 1) == 1) return false;
	}
	return true;
}

int main()
{
	for (int i = 2; ; ++i)
	{
		if (solve(i))
		{
			printf("%d\n", i); // 26
			return 0;
		}
	}
	return 0;
}
