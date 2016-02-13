#include <cstdio>
#include <cstring>

const int mod = 10007;
char s[1002];
int dp[1002][100][1 << 7];
bool can[1002][100][1 << 7];
int pw[1002];

void update(int i, int j, int k, int val)
{
	printf("%d %d %d %d\n", i, j, k, val);
	if (!can[i][j][k])
		can[i][j][k] = true, dp[i][j][k] = 0;
	dp[i][j][k] = (dp[i][j][k] + val) % mod;
}

int main()
{
	while (scanf("%s", s) == 1)
	{
		int K, M;
		scanf("%d %d", &K, &M);
		int n = strlen(s);
		int B = K << 1 | 1;
		for (int i = 0; i <= n; ++i)
			for (int j = 0; j < M; ++j)
				for (int k = 0; k < (1 << B); ++k)
					can[i][j][k] = false;
		can[n][0][(1 << K) - 1] = true;
		dp[n][0][(1 << K) - 1] = 1;
		pw[0] = 1;
		for (int i = 1; i <= n; ++i)
			pw[i] = pw[i - 1] * 10 % M;
		int msk = (1 << B) - 1;
		for (int i = n; i > 0; --i)
		{
			for (int j = 0; j < M; ++j)
			{
				for (int k = 0; k < (1 << B); ++k)
				{
					if (can[i][j][k])
					{
						if (k >> (2 * K) & 1)
						{
							update(i - 1, (j + pw[n - i] * (s[i - 1] - '0')), )
						}
						else
						{
							for (int l = 0; l < K * 2 + 1; ++l)
							{
								if (k >> l & 1)
								{
									update(i - 1, ((j + pw[n - i] * (s[i - 1] - '0') + (pw[n - i - l - 1] - pw[n - i]) * (s[i - 1] - s[i + l])) % M + M) % M, ((k ^ (1 << l)) << 1) & msk, dp[i][j][k]);
								}
							}
						}
					}
				}
			}
		}
		long long ans = 0;
		for (int i = 0; i < (1 << K); ++i)
		{
			ans = (ans + (can[0][0][i] ? dp[0][0][i] : 0)) % mod;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
