#include <cstdio>

long long mul_mod(long long a, long long b, long long mod)
{
	long long ret = 0;
	a %= mod;
	b %= mod;
	while (b)
	{
		if (b & 1)
		{
			ret += a;
			if (ret >= mod)
				ret -= mod;
		}
		a += a;
		if (a >= mod)
			a -= mod;
		b >>= 1;
	}
	return ret;
}

int main()
{
	long long q, P;
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%I64d %I64d", &q, &P);
		if (q <= 2)
			puts("0");
		else
			printf("%I64d\n", mul_mod(q - 1, q - 2, P + P) / 2);
	}
	return 0;
}
