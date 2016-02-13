#include <cstdio>

long long n, m;
int k;
long long a[10000];

long long gcd(long long a, long long b)
{
	return b ? gcd(b, a % b) : a;
}

void gcd(long long a, long long b, long long& d, long long& x, long long& y)
{
	if (!b)
		d = a, x = 1, y = 0;
	else
		gcd(b, a % b, d, y, x), y -= x * (a / b);
}

long long mul_mod(long long a, long long b, long long mod)
{
	long long s = 0;
	b = (b % mod + mod) % mod;
	while (b)
	{
		if (b & 1)
			s = (s + a) % mod;
		a = (a << 1) % mod;
		b >>= 1;
	}
	return s;
}

long long china(int n, long long* a, long long* m, long long M)
{
	long long d, y, x = 0;
	for (int i = 0; i < n; ++i)
	{
		long long w = M / m[i];
		gcd(m[i], w, d, d, y);
		x = (x + mul_mod(mul_mod(y, w, M), a[i], M)) % M;
	}
	return (x + M) % M;
}

long long A[100], M[100];

int main()
{
	scanf("%I64d %I64d %d", &n, &m, &k);
	scanf("%I64d", a);
	long long lcm = a[0];
	bool flag = lcm <= n;
	for (int i = 1; i < k; ++i)
	{
		scanf("%I64d", &a[i]);
		long long g = gcd(a[i], lcm);
		if (a[i] / g > n / lcm)
			flag = false;
		lcm *= a[i] / g;
	}
	if (!flag)
		puts("NO");
	else
	{
		long long t = lcm;
		int N = 0;
		for (int i = 2; 1ll * i * i <= t; ++i)
		{
			if (t % i == 0)
			{
				M[N] = 1;
				while (t % i == 0)
				{
					t /= i;
					M[N] *= i;
				}
				for (int j = 0; j < k; ++j)
					if (a[j] % M[N] == 0)
					{
						A[N] = -j;
						break;
					}
				N++;
			}
		}
		if (t > 1)
		{
			M[N] = t;
			for (int j = 0; j < k; ++j)
				if (a[j] % M[N] == 0)
				{
					A[N] = -j;
					break;
				}
			N++;
		}
		long long ans = china(N, A, M, lcm);
		if (ans == 0)
			ans = lcm;
		if (ans + k - 1 > m)
			puts("NO");
		else
		{
			for (int i = 0; i < k; ++i)
				if (gcd(i + ans, lcm) != a[i])
					flag = false;
			puts(flag ? "YES" : "NO");
		}
	}
	return 0;
}
