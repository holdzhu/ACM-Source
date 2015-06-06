#include <cstdio>
#include <cstring>

long long dp[2][2][1024];
int K;
int num[19];
long long sum[10][19];
int add[1024][10];
int bits[10][1024];
int bitsnum[10];

int decode(long long r)
{
	if (r == 0)
	{
		return 1;
	}
	int p = 0;
	while (r)
	{
		num[p++] = r % 10;
		r /= 10;
	}
	return p;
}

long long solve(long long r)
{
	if (r == 0)
	{
		return 0;
	}
	int p = decode(r);
	memset(dp, 0, sizeof dp);
	for (int i = 1; i < num[p - 1]; ++i)
	{
		dp[0][0][1 << i] = 1;
	}
	dp[0][1][1 << num[p - 1]] = 1;
	bool cur = 0;
	for (int i = p - 2; i >= 0; --i)
	{
		cur = !cur;
		memset(dp[cur], 0, sizeof dp[cur]);
		for (int j = 0; j < 1024; ++j)
		{
			if (dp[!cur][0][j] || dp[!cur][1][j]) for (int k = 0; k < 10; ++k)
			{
				int t = add[j][k];
				if (k < num[i])
				{
					dp[cur][0][t] += dp[!cur][1][j];
				}
				else if (k == num[i])
				{
					dp[cur][1][t] += dp[!cur][1][j];
				}
				dp[cur][0][t] += dp[!cur][0][j];
			}
		}
	}
	long long rnt = 0;
	for (int i = 0; i < bitsnum[K - 1]; ++i)
	{
		rnt += dp[cur][0][bits[K - 1][i]] + dp[cur][1][bits[K - 1][i]];
	}
	return rnt;
}

void init()
{
	for (int i = 0; i < 1024; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			add[i][j] = i;
			for (int k = j; k < 10; ++k)
			{
				if (add[i][j] & (1 << k))
				{
					add[i][j] ^= 1 << k;
					break;
				}
			}
			add[i][j] ^= 1 << j;
		}
	}
	for (int i = 0; i < 10; ++i)
	{
		bitsnum[i] = 0;
	}
	for (int i = 0; i < 1024; ++i)
	{
		int x = i;
		int t = 0;
		while (x)
		{
			t += x & 1;
			x >>= 1;
		}
		if (t)
		{
			t--;
		}
		bits[t][bitsnum[t]++] = i;
	}
	for (K = 1; K <= 10; ++K)
	{
		sum[K - 1][0] = 0;
		long long t = 1;
		for (int i = 1; i < 19; ++i)
		{
			t *= 10;
			sum[K - 1][i] = sum[K - 1][i - 1] + solve(t - 1);
		}
	}
}

int main()
{
	init();
	int t;
	scanf("%d", &t);
	while (t--)
	{
		long long l, r;
		scanf("%lld %lld %d", &l, &r, &K);
		printf("%lld\n", (solve(r) + sum[K - 1][decode(r) - 1]) - (solve(l - 1) + sum[K - 1][decode(l - 1) - 1]));
	}
	return 0;
}
