#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>

const long long mod = 1000000007;

struct Matrix
{
	long long a[4][4];
	Matrix()
	{
		memset(a, 0, sizeof a);
		a[0][1] = a[0][2] = a[1][2] = a[2][0] = a[2][3] = a[3][0] = 1;
	}
	Matrix operator * (const Matrix& rhs)
	{
		Matrix rnt;
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				rnt.a[i][j] = 0;
				for (int k = 0; k < 4; ++k)
				{
					rnt.a[i][j] += (a[i][k] % mod) * (rhs.a[k][j] % mod) % mod;
					rnt.a[i][j] %= mod;
				}
			}
		}
		return rnt;
	}
};

Matrix pow[100];

void init()
{
	pow[0] = Matrix();
	for (int i = 0; i < 80; ++i)
	{
		pow[i + 1] = pow[i] * pow[i];
	}
}

Matrix matrixPow(long long n)
{
	int top = 0;
	Matrix t;
	memset(t.a, 0, sizeof t.a);
	for (int i = 0; i < 4; ++i)
	{
		t.a[i][i] = 1;
	}
	while (n)
	{
		if (n & 1LL)
		{
			t = t * pow[top];
		}
		n >>= 1LL;
		top++;
	}
	return t;
}

long long solve(long long a, long long b, long long c, long long d, long long n)
{
	a %= mod;
	b %= mod;
	c %= mod;
	d %= mod;
	long long out;
	if (n == 0)
	{
		out = (a % mod) * (c % mod) % mod;
	}
	else if (n == 1)
	{
		out = (b % mod) * (d % mod) % mod;
	}
	else
	{
		Matrix t = matrixPow(n - 1);
		long long F = ((((t.a[0][0] % mod) * (b % mod) % mod + (t.a[1][0] % mod) * (a % mod) % mod) % mod + (t.a[2][0] % mod) * (d % mod) % mod) % mod + (t.a[3][0] % mod) * (c % mod) % mod) % mod;
		long long G = ((((t.a[0][2] % mod) * (b % mod) % mod + (t.a[1][2] % mod) * (a % mod) % mod) % mod + (t.a[2][2] % mod) * (d % mod) % mod) % mod + (t.a[3][2] % mod) * (c % mod) % mod) % mod;
		out = F * G % mod;
	}
	if (out < 0)
	{
		out += mod;
	}
	return out;
}

long long solve2(long long a, long long b, long long c, long long d, long long n)
{
	if (n == 0)
	{
		long long rnt = (a % mod) * (c % mod) % mod;
		if (rnt < 0)
		{
			rnt += mod;
		}
		return rnt;
	}
	b %= mod;
	d %= mod;
	for (int i = 0; i < n - 1; ++i)
	{
		long long t1 = (c % mod + d % mod) % mod;
		long long t2 = (a % mod + b % mod) % mod;
		a = b;
		b = t1;
		c = d;
		d = t2;
	}
	long long rnt = (b % mod) * (d % mod) % mod;
	if (rnt < 0)
	{
		rnt += mod;
	}
	return rnt;
}

int main()
{
	init();
	srand((int)time(0));
	while (1)
	{
		long long a, b, c, d, n;
		a = ((long long)rand() * rand() - 100000000) * rand() * rand() * rand() * rand() * rand() * rand() * rand();
		b = ((long long)rand() * rand() - 100000000) * rand() * rand() * rand() * rand() * rand() * rand() * rand();
		c = ((long long)rand() * rand() - 100000000) * rand() * rand() * rand() * rand() * rand() * rand() * rand();
		d = ((long long)rand() * rand() - 100000000) * rand() * rand() * rand() * rand() * rand() * rand() * rand();
		n = rand() * rand();
		printf("%lld %lld %lld %lld %lld\n", a, b, c, d, n);
		long long s = solve(a, b, c, d, n);
		long long s2 = solve2(a, b, c, d, n);
		if (s != s2)
		{
			printf("!!! %lld %lld\n", s, s2);
			break;
		}
		else
		{
			printf("YES\n");
		}
	}
	return 0;
}
