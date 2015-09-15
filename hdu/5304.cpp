#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int mod = 998244353;

struct Atom
{
	long long x, y;
};

Atom operator - (const Atom& k1, const Atom& k2)
{
	return (Atom){(k1.x - k2.x + mod) % mod, (k1.y - k2.y + mod) % mod};
}

Atom operator * (const Atom& k1, const int& k2)
{
	return (Atom){k1.x * k2 % mod, k1.y * k2 % mod};
}

bool G[16][16];
int dp[1 << 16][16];
int cnt[1 << 16];
int bits[16];
int id[16];
int matrix[16][16];

int gauss(int n)
{
	int sign = 1;
	n--;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			matrix[i][j] = (matrix[i][j] + mod) % mod;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		int r = -1;
		for (int j = i; j < n; ++j)
		{
			if (matrix[j][i] != 0)
			{
				r = j;
				break;
			}
		}
		if (r == -1)
		{
			return 0;
		}
		if (r != i)
		{
			for (int j = i; j < n; ++j)
			{
				swap(matrix[i][j], matrix[r][j]);
			}
			sign = -sign;
		}
		for (int j = i + 1; j < n; ++j)
		{
			int k1 = matrix[i][i];
			int k2 = matrix[j][i];
			Atom a1 = (Atom){1, 0};
			Atom a2 = (Atom){0, 1};
			while (k2)
			{
				a1 = a1 - a2 * (k1 / k2);
				swap(a1, a2);
				k1 %= k2;
				swap(k1, k2);
				sign = -sign;
			}
			for (int k = i; k < n; ++k)
			{
				k1 = matrix[i][k];
				k2 = matrix[j][k];
				matrix[i][k] = ((long long)k1 * a1.x + (long long)k2 * a1.y) % mod;
				matrix[j][k] = ((long long)k1 * a2.x + (long long)k2 * a2.y) % mod;
			}
		}
	}
	long long rnt = sign;
	for (int i = 0; i < n; ++i)
	{
		rnt = rnt * matrix[i][i] % mod;
	}
	return (rnt + mod) % mod;
}

int main()
{
	int n, m;
	while (scanf("%d %d", &n, &m) == 2)
	{
		memset(G, 0, sizeof G);
		for (int i = 0; i < m; ++i)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			u--;
			v--;
			G[u][v] = 1;
			G[v][u] = 1;
		}
		memset(cnt, 0, sizeof cnt);
		for (int s = 0; s < n; ++s)
		{
			memset(dp, 0, sizeof dp);
			dp[1 << s][s] = 1;
			for (int i = 0; i < (1 << n); ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					if (dp[i][j] > 0)
					{
						for (int k = s + 1; k < n; ++k)
						{
							if ((i & (1 << k)) == 0 && G[j][k])
							{
								dp[i | (1 << k)][k] = (dp[i | (1 << k)][k] + dp[i][j]) % mod;
							}
						}
						if (G[j][s])
						{
							cnt[i] = (cnt[i] + dp[i][j]) % mod;
						}
					}
				}
			}
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				if (G[i][j])
				{
					cnt[(1 << i) | (1 << j)] = (cnt[(1 << i) | (1 << j)] - 1 + mod) % mod;
				}
			}
		}
		int inv2 = (mod + 1) >> 1;
		for (int i = 0; i < (1 << n); ++i)
		{
			cnt[i] = (long long)cnt[i] * inv2 % mod;
		}
		int ans = 0;
		for (int i = 0; i < (1 << n); ++i)
		{
			int num = 1;
			for (int j = 0; j < n; ++j)
			{
				bits[j] = i & (1 << j);
			}
			for (int j = 0; j < n; ++j)
			{
				if (bits[j])
				{
					id[j] = 0;
				}
				else
				{
					id[j] = num++;
				}
			}
			memset(matrix, 0, sizeof matrix);
			for (int j = 0; j < n; ++j)
			{
				for (int k = 0; k < n; ++k)
				{
					if (G[j][k] && id[j] != id[k])
					{
						matrix[id[j]][id[k]]--;
						matrix[id[j]][id[j]]++;
					}
				}
			}
			ans = (ans + (long long)cnt[i] * gauss(num)) % mod;
		}
		printf("%d\n", ans);
	}
	return 0;
}
