#include <cstdio>

long long fac[100001];
long long inv[100001];
long long facinv[100001];

int count(int x, int m)
{
	int rnt = 0;
	while (x)
	{
		x /= m;
		rnt += x;
	}
	return rnt;
}

long long solve(int n, int m, int p)
{
	long long rnt = 1;
	while (n && m)
	{
		int N = n % p;
		int M = m % p;
		rnt = rnt * fac[M] % p * facinv[N] % p * facinv[M - N] % p;
		n /= p;
		m /= p;
	}
	return rnt;
}

int main()
{
	int t;
	scanf("%d", &t);
	inv[1] = 1;
	fac[0] = fac[1] = 1;
	facinv[0] = facinv[1] = 1;
	while (t--)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		if (count(n * 2, m) > count(n, m) + count(n + 1, m))
		{
			printf("0\n");
			continue;
		}
		for (int i = 2; i < m; ++i)
		{
			inv[i] = inv[m % i] * (m - m / i) % m;
			fac[i] = fac[i - 1] * i % m;
			facinv[i] = facinv[i - 1] * inv[i] % m;
		}
		printf("%lld\n", (solve(n, n * 2, m) - solve(n + 1, n * 2, m) + m) % m);
	}
	return 0;
}
