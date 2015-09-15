#include <cstdio>

const int mod = 1000000007;
long long n;
int m;
int blocks[24];
long long dp[1 << 7][1 << 7];
long long tmp[1 << 7][1 << 7];
long long ans[1 << 7][1 << 7];

void dfs(int d, int val)
{
	if (d == (m - 1) * 4)
	{
		int low = (~val) & ((1 << m) - 1);
		int high = val >> m;
		dp[low][high]++;
	}
	else
	{
		if ((val & blocks[d]) == 0)
		{
			dfs(d + 1, val | blocks[d]);
		}
		dfs(d + 1, val);
	}
}

int main()
{
	scanf("%lld %d", &n, &m);
	blocks[0] = 3 + (1 << m);
	blocks[1] = 3 + (1 << (m + 1));
	blocks[2] = 1 + (1 << m) + (1 << (m + 1));
	blocks[3] = 2 + (1 << m) + (1 << (m + 1));
	for (int i = 0; i < m - 2; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			blocks[i * 4 + j + 4] = blocks[i * 4 + j] << 1;
		}
	}
	dfs(0, 0);
	for (int i = 0; i < (1 << m); ++i)
	{
		ans[i][i] = 1;
	}
	n--;
	while (n)
	{
		if (n & 1)
		{
			for (int i = 0; i < (1 << m); ++i)
			{
				for (int j = 0; j < (1 << m); ++j)
				{
					tmp[i][j] = 0;
					for (int k = 0; k < (1 << m); ++k)
					{
						tmp[i][j] = (tmp[i][j] + ans[i][k] * dp[k][j]) % mod;
					}
				}
			}
			for (int i = 0; i < (1 << m); ++i)
			{
				for (int j = 0; j < (1 << m); ++j)
				{
					ans[i][j] = tmp[i][j];
				}
			}
		}
		for (int i = 0; i < (1 << m); ++i)
		{
			for (int j = 0; j < (1 << m); ++j)
			{
				tmp[i][j] = 0;
				for (int k = 0; k < (1 << m); ++k)
				{
					tmp[i][j] = (tmp[i][j] + dp[i][k] * dp[k][j]) % mod;
				}
			}
		}
		for (int i = 0; i < (1 << m); ++i)
		{
			for (int j = 0; j < (1 << m); ++j)
			{
				dp[i][j] = tmp[i][j];
			}
		}
		n >>= 1;
	}
	printf("%lld\n", ans[0][(1 << m) - 1]);
	return 0;
}
