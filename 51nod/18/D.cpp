#include <cstdio>
#include <cstring>

int n, m;
long long dp[1 << 22][22];
int msk[21][22];

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

int idx(int x, int y)
{
	return x * m + y;
}

int main()
{
	freopen("D.out", "w", stdout);
	for (n = 1; n <= 64; ++n)
	{
		for (m = 1; m <= 64; ++m)
		{
			if (n * m > 22)
			{
				printf("0,");
				continue;
			}
			for (int i = 0; i < (1 << (n * m)); ++i)
				for (int j = 0; j < n * m; ++j)
					dp[i][j] = 0;
			for (int i = 0; i < n * m; ++i)
				for (int j = 0; j < n * m; ++j)
					msk[i][j] = 0;
			for (int i1 = 0; i1 < n; ++i1)
			{
				for (int j1 = 0; j1 < m; ++j1)
				{
					for (int i2 = 0; i2 < n; ++i2)
					{
						for (int j2 = 0; j2 < m; ++j2)
						{
							if (i1 == i2 && j1 == j2)
								continue;
							int id1 = idx(i1, j1);
							int id2 = idx(i2, j2);
							int dx = i1 - i2;
							int dy = j1 - j2;
							int g = gcd(dx, dy);
							dx /= g;
							dy /= g;
							if ((dx > 0 && i1 > i2) || (dx < 0 && i1 < i2) || (dy > 0 && j1 > j2) || (dy < 0 && j1 < j2))
							{
								dx = -dx;
								dy = -dy;
							}
							int u = i1 + dx;
							int v = j1 + dy;
							while (u != i2 || v != j2)
							{
								msk[id1][id2] |= 1 << idx(u, v);
								u += dx;
								v += dy;
							}
						}
					}
				}
			}
			for (int i = 0; i < n * m; ++i)
			{
				dp[1 << i][i] = 1;
			}
			for (int i = 0; i < (1 << (n * m)); ++i)
			{
				for (int j = 0; j < n * m; ++j)
				{
					if (i >> j & 1)
					{
						for (int k = 0; k < n * m; ++k)
						{
							if (!(i >> k & 1) && (i & msk[j][k]) == msk[j][k])
							{
								dp[i | (1 << k)][k] += dp[i][j];
							}
						}
					}
				}
			}
			long long ans = 0;
			for (int i = 0; i < n * m; ++i)
				ans += dp[(1 << (n * m)) - 1][i];
			printf("%lld,", ans);
			
		}
		printf("\n");
	}
	return 0;
}
