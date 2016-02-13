#include <cstdio>
#include <cstring>
#include <cmath>

const int maxv = 10000;
const int maxp = 100;
const int maxn = 100000;
int n, M;
bool isprime[maxn];
int lastprime[maxn];
int SQRT[maxn];
int inv[2000];
short dp[maxv + 1][maxp + 1];
short dp2[maxv + 1][maxp + 1];
int FAC[maxn];
int mul[maxn];

int pow_mod(int a, int n)
{
	a %= M;
	int ret = 1;
	while (n)
	{
		if (n & 1)
		{
			ret = ret * a % M;
		}
		a = a * a % M;
		n >>= 1;
	}
	return ret;
}

int fac(int x)
{
	if (x <= 1)
	{
		return 1;
	}
	if (x < maxn && FAC[x] != -1)
	{
		return FAC[x];
	}
	int ret = 1;
	ret = ret * pow_mod(mul[M - 1], x / M) % M;
	ret = ret * mul[x % M] % M;
	if (x >= maxn)
	{
		return ret * fac(x / M) % M;
	}
	return FAC[x] = ret * fac(x / M) % M;
}

int S(int v, int p)
{
	if (p <= 1)
	{
		return v - 1;
	}
	if (v <= maxv && p <= maxp)
	{
		if (dp[v][p] != -1)
		{
			return dp[v][p];
		}
		if (!isprime[p] || v < p * p)
		{
			return dp[v][p] = S(v, lastprime[p - 1]);
		}
		return dp[v][p] = S(v, lastprime[p - 1]) - S(v / p, lastprime[p - 1]) + S(p - 1, lastprime[SQRT[p - 1]]);
	}
	if (!isprime[p] || v < p * p)
	{
		return S(v, lastprime[p - 1]);
	}
	return S(v, lastprime[p - 1]) - S(v / p, lastprime[p - 1]) + S(p - 1, lastprime[SQRT[p - 1]]);
}

int F(int v, int p)
{
	if (p <= 1)
	{
		return fac(v);
	}
	if (v <= maxv && p <= maxp)
	{
		if (dp2[v][p] != -1)
		{
			return dp2[v][p];
		}
		if (!isprime[p] || v < p * p)
		{
			return dp2[v][p] = F(v, lastprime[p - 1]);
		}
		return dp2[v][p] = F(v, lastprime[p - 1]) * inv[pow_mod(p, S(v / p, lastprime[p - 1]) - S(p - 1, lastprime[SQRT[p - 1]]))] % M
		* inv[F(v / p, lastprime[p - 1])] % M * F(p - 1, lastprime[SQRT[p - 1]]) % M;
	}
	if (!isprime[p] || v < p * p)
	{
		return F(v, lastprime[p - 1]);
	}
	return F(v, lastprime[p - 1]) * inv[pow_mod(p, S(v / p, lastprime[p - 1]) - S(p - 1, lastprime[SQRT[p - 1]]))] % M
	* inv[F(v / p, lastprime[p - 1])] % M * F(p - 1, lastprime[SQRT[p - 1]]) % M;
}

void init()
{
	for (int i = 1; i < maxn; ++i)
	{
		isprime[i] = true;
		SQRT[i] = sqrt(i + 0.5);
	}
	for (int i = 2; i < maxn; ++i)
	{
		if (isprime[i] && i < 40000)
		{
			for (int j = i * i; j < maxn; j += i)
			{
				isprime[j] = false;
			}
		}
	}
	for (int i = 1; i < maxn; ++i)
	{
		lastprime[i] = isprime[i] ? i : lastprime[i - 1];
	}
}

int main()
{
	init();
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		memset(dp, -1, sizeof dp);
		memset(dp2, -1, sizeof dp2);
		memset(FAC, -1, sizeof FAC);
		scanf("%d %d", &n, &M);
		inv[0] = inv[1] = 1;
		mul[0] = mul[1] = 1;
		for (int i = 2; i < M; ++i)
		{
			inv[i] = (M - M / i) * inv[M % i] % M;
			mul[i] = mul[i - 1] * i % M;
		}
		printf("Case #%d: %d\n", kase, F(n, sqrt(n + 0.5)));
	}
	return 0;
}
