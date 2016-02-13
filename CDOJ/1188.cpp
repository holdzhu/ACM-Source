#include <cstdio>
#include <cmath>
#include <map>
#include <vector>

using namespace std;

const int maxn = 100000;

vector<int> primes, p, bigstep, smallstep, root, inv;
vector<map<long long, long long> > pre;
bool notprime[maxn + 1];

long long powmod(long long a, long long p, long long mod)
{
	long long ret = 1;
	while (p)
	{
		if (p & 1)
		{
			ret = ret * a % mod;
		}
		a = a * a % mod;
		p >>= 1;
	}
	return ret;
}

long long exgcd(long long a, long long b, long long& x, long long& y)
{
	if (!b)
	{
		x = 1;
		y = 0;
		return a;
	}
	long long d = exgcd(b, a % b, y, x);
	y -= x * (a / b);
	return d;
}

void initprimes()
{
	for (int i = 2; i <= maxn; ++i)
	{
		if (!notprime[i])
		{
			primes.push_back(i);
		}
		if (maxn / i >= i)
		{
			for (int j = i * i; j <= maxn; j += i)
			{
				notprime[j] = true;
			}
		}
	}
}

long long primelog(int i, long long x)
{
	x %= p[i];
	long long prod = 1;
	for (int j = 0; j < smallstep[i]; ++j)
	{
		if (pre[i].count(x * prod % p[i]))
		{
			return pre[i][x * prod % p[i]] + j * bigstep[i];
		}
		prod = prod * inv[i] % p[i];
	}
	return -1;
}

void factor(int n, vector<int>& p)
{
	for (int i = 0; i < primes.size() && primes[i] * primes[i] <= n && n > 1; ++i)
	{
		if (n % primes[i] == 0)
		{
			while (n % primes[i] == 0)
			{
				n /= primes[i];
			}
			p.push_back(primes[i]);
		}
	}
	if (n > 1)
	{
		p.push_back(n);
	}
}

int calcroot(int p)
{
	vector<int> t;
	factor(p - 1, t);
	for (int i = 1; ; ++i)
	{
		bool flag = true;
		for (int j = 0; j < t.size(); ++j)
		{
			if (powmod(i, (p - 1) / t[j], p) == 1)
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			return i;
		}
	}
}

int main()
{
	initprimes();
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		int sum, m;
		scanf("%d %d", &sum, &m);
		p.clear();
		factor(sum, p);
		pre.clear();
		pre.resize(p.size());
		inv.resize(p.size());
		root.resize(p.size());
		smallstep.resize(p.size());
		bigstep.resize(p.size());
		for (int i = 0; i < p.size(); ++i)
		{
			root[i] = calcroot(p[i]);
			smallstep[i] = ceil(sqrt(1.0 * p[i] / m));
			bigstep[i] = (p[i] - 1) / smallstep[i] + 1;
			long long prod = 1;
			for (int j = 0; j < bigstep[i]; ++j)
			{
				pre[i][prod] = j;
				prod = prod * root[i] % p[i];
			}
			inv[i] = powmod(prod, p[i] - 2, p[i]);
		}
		printf("Case #%d:\n", kase);
		while (m--)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			int k = 1e9 + 10;
			for (int i = 0; i < p.size(); ++i)
			{
				long long lx = primelog(i, x);
				long long ly = primelog(i, y);
				if (lx == -1 || ly == -1)
				{
					continue;
				}
				long long d, gx, gy;
				d = exgcd(lx, p[i] - 1, gx, gy);
				if (d < 0)
				{
					d = -d;
					gx = -gx;
					gy = -gy;
				}
				if (ly % d == 0)
				{
					k = min(k, (int)(((ly / d * gx % ((p[i] - 1) / d)) + ((p[i] - 1) / d)) % ((p[i] - 1) / d)));
				}
			}
			printf("%d\n", k == 1e9 + 10 ? -1 : k);
		}
	}
	return 0;
}
