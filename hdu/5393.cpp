#include <cstdio>
#include <cmath>
#include <map>
#include <vector>

using namespace std;

map<long long, int> factor;

long long gcd(long long a, long long b)
{
	return b ? gcd(b, a % b) : a;
}

long long multi_mod(long long a, long long b, long long c)
{
	a %= c;
	b %= c;
	long long rnt = 0;
	while (b)
	{
		if (b & 1)
		{
			rnt += a;
			if (rnt >= c)
			{
				rnt -= c;
			}
		}
		a <<= 1;
		if (a >= c)
		{
			a -= c;
		}
		b >>= 1;
	}
	return rnt;
}

long long pow_mod(long long a, long long p, long long n)
{
	long long s = 1;
	while (p)
	{
		if (p & 1)
		{
			s = multi_mod(s, a, n);
		}
		a = multi_mod(a, a, n);
		p >>= 1;
	}
	return s;
}

void multiply(long long x)
{
	long long m = sqrt(x + 0.5);
	for (int i = 2; i <= m && x > 1; ++i)
	{
		int cnt = 0;
		while (x % i == 0)
		{
			x /= i;
			cnt++;
		}
		if (cnt)
		{
			factor[i] += cnt;
		}
	}
	if (x > 1)
	{
		factor[x]++;
	}
}

void divide(long long x)
{
	long long m = sqrt(x + 0.5);
	for (int i = 2; i <= m && x > 1; ++i)
	{
		int cnt = 0;
		while (x % i == 0)
		{
			x /= i;
			cnt++;
		}
		if (cnt)
		{
			factor[i] -= cnt;
		}
	}
	if (x > 1)
	{
		factor[x]--;
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int k, b, x0, p;
		scanf("%d %d %d %d", &k, &b, &x0, &p);
		if (k == 0)
		{
			puts(x0 == b ? "1" : "-1");
		}
		else if (k == 1)
		{
			printf("%I64d\n", p / gcd(p, b));
		}
		else
		{
			factor.clear();
			long long d = gcd(1ll * (k - 1) * x0 + b, 1ll * (k - 1) * p);
			long long q = 1ll * (k - 1) * p / d;
			multiply(k - 1);
			multiply(p);
			divide(d);
			vector<long long> pp;
			for (map<long long, int>::iterator it = factor.begin(); it != factor.end(); ++it)
			{
				if (it->second > 0)
				{
					pp.push_back(it->first);
					it->second--;
				}
			}
			for (int i = 0; i < pp.size(); ++i)
			{
				multiply(pp[i] - 1);
			}
			long long phi = 1;
			for (map<long long, int>::iterator it = factor.begin(); it != factor.end(); ++it)
			{
				for (int i = 0; i < it->second; ++i)
				{
					phi *= it->first;
				}
			}
			long long ans = phi;
			for (map<long long, int>::iterator it = factor.begin(); it != factor.end(); ++it)
			{
				while (ans % it->first == 0)
				{
					if (pow_mod(k, ans / it->first, q) == 1)
					{
						ans /= it->first;
					}
					else
					{
						break;
					}
				}
			}
			printf("%I64d\n", ans);
		}
	}
	return 0;
}
