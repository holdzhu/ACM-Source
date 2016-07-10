#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

const int mod = 1e9 + 7;

long long inv(long long a)
{
	int k = mod - 2;
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

const int maxn = 1e5;

struct LD
{
	long double x;
	int two;
	int five;
	void operator+=(const LD &rhs)
	{
		x += rhs.x;
		two += rhs.two;
		five += rhs.five;
	}
	LD operator-(const LD &rhs) const
	{
		return {x - rhs.x, two - rhs.two, five - rhs.five};
	}
};

LD ld[maxn];
long double ld2[maxn];
long long ll[maxn];
int F[maxn];
vector<int> fac[maxn];

LD get(int f)
{
	while (f % 10 == 0)
		f /= 10;
	int two = 0, five = 0;
	while (f % 2 == 0)
		f /= 2, ++two;
	while (f % 5 == 0)
		f /= 5, ++five;
	return {log10f(f), two, five};
}

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		scanf("%d", &F[i]), ll[i] = 1;
	if (N <= 10)
	{
		for (int i = 1; i < N; ++i)
			for (int j = 1; i * j < N; ++j)
			{
				ld[i] += get(F[i * j]);
				ll[i] = ll[i] * F[i * j] % mod;
				fac[i * j].push_back(i);
			}
		int Q;
		scanf("%d", &Q);
		while (Q--)
		{
			int cmd;
			scanf("%d", &cmd);
			if (cmd == 1)
			{
				int p, f;
				scanf("%d %d", &p, &f);
				if (p == 1)
					F[0] = f;
				else
				{
					LD delta = get(f) - get(F[p - 1]);
					long long mul = f * inv(F[p - 1]) % mod;
					for (int v : fac[p - 1])
					{
						ld[v] += delta;
						ll[v] = ll[v] * mul % mod;
					}
					F[p - 1] = f;
				}
			}
			else
			{
				int R;
				scanf("%d", &R);
				LD ansld = get(F[0]);
				long long ansll = F[0];
				if (R < N)
				{
					ansld += ld[R];
					ansll = ansll * ll[R] % mod;
				}
				long double d = ansld.x;
				if (ansld.two > ansld.five)
					d += log10f(2) * (ansld.two - ansld.five);
				else
					d += log10f(5) * (ansld.five - ansld.two);
				printf("%d %lld\n",
					   (int)(powl(10, d - (long long)d) + 1e-15l),
					   ansll);
			}
		}
	}
	else
	{
		for (int i = 1; i < N; ++i)
			for (int j = 1; i * j < N; ++j)
			{
				ld2[i] += log10l(F[i * j]);
				ll[i] = ll[i] * F[i * j] % mod;
				fac[i * j].push_back(i);
			}
		int Q;
		scanf("%d", &Q);
		while (Q--)
		{
			int cmd;
			scanf("%d", &cmd);
			if (cmd == 1)
			{
				int p, f;
				scanf("%d %d", &p, &f);
				if (p == 1)
					F[0] = f;
				else
				{
					long double delta = log10l(f) - log10l(F[p - 1]);
					long long mul = f * inv(F[p - 1]) % mod;
					for (int v : fac[p - 1])
					{
						ld2[v] += delta;
						ll[v] = ll[v] * mul % mod;
					}
					F[p - 1] = f;
				}
			}
			else
			{
				int R;
				scanf("%d", &R);
				long double ansld = log10l(F[0]);
				long long ansll = F[0];
				if (R < N)
				{
					ansld += ld2[R];
					ansll = ansll * ll[R] % mod;
				}
				printf("%d %lld\n",
					   (int)(powl(10, ansld - (long long)ansld) + 1e-18l),
					   ansll);
			}
		}
	}

	return 0;
}
