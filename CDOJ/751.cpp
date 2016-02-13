#include <cstdio>
#include <cstring>
#include <cmath>

const int maxv = 1000;
const int maxp2 = 11630;
const int maxp = 31630;
bool isprime[maxp + 1];
int lastprime[maxp + 1];
int SQRT[maxp + 1];
int dp[maxv + 1][maxp2 + 1];

int S(int v, int p)
{
	if (p <= 1)
	{
		return v - 1;
	}
	if (v <= maxv && p <= maxp2)
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

int solve(int n)
{
	return n == 0 ? 0 : S(n, sqrt(n + 0.5));
}

void init()
{
	memset(dp, -1, sizeof dp);
	for (int i = 1; i <= maxp; ++i)
	{
		isprime[i] = true;
		SQRT[i] = sqrt(i + 0.5);
	}
	for (int i = 2; i <= maxp; ++i)
	{
		if (isprime[i])
		{
			for (int j = i * i; j <= maxp; j += i)
			{
				isprime[j] = false;
			}
		}
		lastprime[i] = isprime[i] ? i : lastprime[i - 1];
	}
}

int main()
{
	init();
	int n, m;
	while (scanf("%d %d", &n, &m) == 2 && n && m)
	{
		printf("%d\n", solve(m) - solve(n - 1));
	}
	return 0;
}
