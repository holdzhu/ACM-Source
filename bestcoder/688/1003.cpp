#include <cstdio>

long long A[3][3];
long long tmp[3][3];
long long S[3][3];

long long pow_mod(long long a, long long b, long long mod)
{
	a %= mod;
	b %= mod;
	long long ret = 1;
	while (b)
	{
		if (b & 1)
			ret = ret * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ret;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		long long n, a, b, c, p;
		scanf("%I64d %I64d %I64d %I64d %I64d", &n, &a, &b, &c, &p);
		A[0][0] = c % p;
		A[0][1] = A[0][2] = A[1][0] = A[2][2] = 1;
		A[1][1] = A[1][2] = A[2][0] = A[2][1] = 0;
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				S[i][j] = i == j;
		--n;
		while (n)
		{
			if (n & 1)
			{
				for (int i = 0; i < 3; ++i)
					for (int j = 0; j < 3; ++j)
					{
						tmp[i][j] = 0;
						for (int k = 0; k < 3; ++k)
							tmp[i][j] = (tmp[i][j] + S[i][k] * A[k][j] % (p - 1)) % (p - 1);
					}
				for (int i = 0; i < 3; ++i)
					for (int j = 0; j < 3; ++j)
						S[i][j] = tmp[i][j];
			}
			for (int i = 0; i < 3; ++i)
				for (int j = 0; j < 3; ++j)
				{
					tmp[i][j] = 0;
					for (int k = 0; k < 3; ++k)
						tmp[i][j] = (tmp[i][j] + A[i][k] * A[k][j] % (p - 1)) % (p - 1);
				}
			for (int i = 0; i < 3; ++i)
				for (int j = 0; j < 3; ++j)
					A[i][j] = tmp[i][j];
			n >>= 1;
		}
		long long pw = (S[1][0] + S[1][2]) % (p - 1);
		long long base = pow_mod(a, b, p);
		printf("%I64d\n", pow_mod(base, pw, p));
	}
	return 0;
}
