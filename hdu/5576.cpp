#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int mod = 1000000007;

char s[51];
int pows[101];
int dp[2][50][50][50];
int sum[3][50][50];

inline void update(int &x, int value)
{
	x += value;
	if (x >= mod)
	{
		x -= mod;
	}
}

int main()
{
	pows[0] = 1;
	for (int i = 1; i <= 100; ++i)
	{
		pows[i] = 1ll * pows[i - 1] * 10 % mod;
	}
	int T;
	scanf("%d", &T);
	for (int kase = 1; T--; ++kase)
	{
		int K;
		scanf("%d", &K);
		scanf("%s", s);
		int L = strlen(s);
		int (*y)[50][50] = dp[0], (*x)[50][50] = dp[1];
		for (int i = 0; i < L; ++i)
		{
			for (int j = 0; j < L; ++j)
			{
				for (int k = 0; k < L; ++k)
				{
					y[i][j][k] = i < k && k < j ? pows[k + L - i - j - 2] : 0;
				}
			}
		}
		for (int it = 1; it <= K; ++it)
		{
			swap(x, y);
			for (int i = 0; i < L; ++i)
			{
				for (int j = 0; j < L; ++j)
				{
					sum[0][i][j] = sum[1][i][j] = sum[2][i][j] = 0;
					for (int k = 0; k < L; ++k)
					{
						update(sum[0][i][j], x[k][i][j]);
						update(sum[1][i][j], x[i][k][j]);
						update(sum[2][i][j], x[i][j][k]);
					}
				}
			}
			for (int i = 0; i < L; ++i)
			{
				for (int j = 0; j < L; ++j)
				{
					for (int k = 0; k < L; ++k)
					{
						y[i][j][k] = 0;
						if (i != j && i != k && j != k)
						{
							update(y[i][j][k], sum[0][j][k]);
							update(y[i][j][k], sum[1][i][k]);
							update(y[i][j][k], sum[2][i][j]);
							update(y[i][j][k], x[j][i][k]);
							update(y[i][j][k], x[k][j][i]);
							update(y[i][j][k], x[i][k][j]);
							update(y[i][j][k], 1ll * x[i][j][k] * ((L - 4) * (L - 3) / 2 + mod - 3) % mod);
						}
					}
				}
			}
		}
		int mpos = -1;
		while (s[++mpos] != '*');
		int ans = 0;
		for (int i = 0; i < L; ++i)
		{
			for (int j = 0; j < L; ++j)
			{
				if (i != j && i != mpos && j != mpos)
				{
					update(ans, 1ll * (s[i] - '0') * (s[j] - '0') * y[i][j][mpos] % mod);
				}
			}
		}
		printf("Case #%d: %d\n", kase, ans);
	}
	return 0;
}
