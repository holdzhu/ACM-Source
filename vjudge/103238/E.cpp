#include <cstdio>

long long mod;

long long mul_mod(long long a, long long b)
{
	long long s = 0;
	while (b)
	{
		if (b & 1)
			s = (s + a) % mod;
		a = (a + a) % mod;
		b >>= 1;
	}
	return s;
}

long long tmp[2][2];

void mul(long long A[2][2], long long B[2][2])
{
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
		{
			tmp[i][j] = 0;
			for (int k = 0; k < 2; ++k)
				tmp[i][j] = (tmp[i][j] + mul_mod(A[i][k], B[k][j])) % mod;
		}
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			A[i][j] = tmp[i][j];
}

long long s[2][2], a[2][2];

long long solve(int n)
{
	s[0][0] = s[1][1] = 1;
	s[0][1] = s[1][0] = 0;
	a[0][0] = 3;
	a[0][1] = mod - 1;
	a[1][0] = 1;
	a[1][1] = 0;
	while (n)
	{
		if (n & 1)
			mul(s, a);
		mul(a, a);
		n >>= 1;
	}
	return (s[1][0] * 3 + s[1][1] * 2 + mod - 2) % mod;
}

int n, m;
int p[100], c[100];
int cnt;
long long ans;

void dfs(int i, int d, int phi)
{
	if (i == cnt)
		ans = (ans + mul_mod(phi, solve(n / d))) % mod;
	else
	{
		dfs(i + 1, d, phi);
		phi *= p[i] - 1;
		for (int j = 1; j <= c[i]; ++j, phi *= p[i])
			dfs(i + 1, d *= p[i], phi);
	}
}

int main()
{
	while (scanf("%d %d", &n, &m) == 2)
	{
		cnt = 0;
		int t = n;
		for (int i = 2; i * i <= t; ++i)
			if (t % i == 0)
			{
				c[cnt] = 0;
				while (t % i == 0)
					t /= i, c[cnt]++;
				p[cnt++] = i;
			}
		if (t > 1)
			p[cnt] = t, c[cnt++] = 1;
		mod = 1ll * n * m;
		ans = 0;
		dfs(0, 1, 1);
		printf("%I64d\n", ans / n);
	}
	return 0;
}
