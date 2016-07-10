#include <cstdio>

const int mod = 1e9 + 7;

long long s[2][2];
long long a[2][2];
long long tmp[2][2];

void mul(long long A[2][2], long long B[2][2])
{
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
		{
			tmp[i][j] = 0;
			for (int k = 0; k < 2; ++k)
				tmp[i][j] = (tmp[i][j] + A[i][k] * B[k][j] % mod) % mod;
		}
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			A[i][j] = tmp[i][j];
}

int main()
{
	int A, B, x;
	long long n;
	scanf("%d %d %I64d %d", &A, &B, &n, &x);
	s[0][0] = s[1][1] = 1;
	a[0][0] = A;
	a[0][1] = B;
	a[1][1] = 1;
	while (n)
	{
		if (n & 1)
			mul(s, a);
		mul(a, a);
		n >>= 1;
	}
	long long ans = 1ll * s[0][0] * x % mod + s[0][1];
	ans %= mod;
	printf("%I64d\n", ans);
	return 0;
}
