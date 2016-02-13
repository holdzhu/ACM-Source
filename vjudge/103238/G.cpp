#include <cstdio>

const int mod = 9901;
int s[2][2];
int a[2][2];
int tmp[2][2];

void mul(int A[2][2], int B[2][2])
{
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
		{
			tmp[i][j] = 0;
			for (int k = 0; k < 2; ++k)
				tmp[i][j] = (tmp[i][j] + A[i][k] * B[k][j]) % mod;
		}
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			A[i][j] = tmp[i][j];
}

int powmod(int p, long long k)
{
	a[0][0] = p % mod;
	a[1][0] = 0;
	a[0][1] = a[1][1] = 1;
	s[0][0] = s[1][1] = 1;
	s[0][1] = s[1][0] = 0;
	while (k)
	{
		if (k & 1)
			mul(s, a);
		mul(a, a);
		k >>= 1;
	}
	return (s[0][0] + s[0][1]) % mod;
}

int main()
{
	int A, B;
	scanf("%d %d", &A, &B);
	if (A == 0)
	{
		puts("0");
		return 0;
	}
	int ans = 1;
	for (int i = 2; i * i <= A; ++i)
		if (A % i == 0)
		{
			int cnt = 0;
			while (A % i == 0)
				A /= i, cnt++;
			ans = ans * powmod(i, 1ll * cnt * B) % mod;
		}
	if (A > 1)
		ans = ans * powmod(A, B) % mod;
	printf("%d\n", ans);
	return 0;
}
