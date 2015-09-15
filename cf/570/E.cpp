#include <cstdio>
#include <cstring>

const int mod = 1000000007;
int n, m;
char s[500][501];
long long dp[2][500][500];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", s[i]);
	}
	bool cur = 0;
	int longest = (n + m) / 2 - 1;
	memset(dp, 0, sizeof dp);
	for (int x1 = 0; x1 < n; ++x1)
	{
		int y1 = longest - x1;
		for (int x2 = x1; x2 < n; ++x2)
		{
			int y2 = m - 1 - (longest - (n - 1 - x2));
			if (x1 <= x2 && y1 <= y2 && s[x1][y1] == s[x2][y2])
			{
				dp[0][x1][x2] = 1;
			}
		}
	}
	for (int i = longest - 1; i >= 0; --i)
	{
		cur = !cur;
		memset(dp[cur], 0, sizeof dp[cur]);
		for (int x1 = 0; x1 < n; ++x1)
		{
			int y1 = i - x1;
			for (int x2 = x1; x2 < n; ++x2)
			{
				int y2 = m - 1 - (i - (n - 1 - x2));
				if (x1 <= x2 && y1 <= y2 && s[x1][y1] == s[x2][y2])
				{
					dp[cur][x1][x2] = (dp[!cur][x1][x2] + dp[!cur][x1 + 1][x2] + dp[!cur][x1][x2 - 1] + dp[!cur][x1 + 1][x2 - 1]) % mod;
				}
			}
		}
	}
	printf("%I64d\n", dp[cur][0][n - 1]);
	return 0;
}
