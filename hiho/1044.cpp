#include <cstdio>
#include <cstring>

inline int max(int a, int b)
{
	return a > b ? a : b;
}

int countbit(int x)
{
	int t = 0;
	while (x)
	{
		t += x & 1;
		x >>= 1;
	}
	return t;
}

int main()
{
	int N, M, Q;
	scanf("%d %d %d", &N, &M, &Q);
	int maxm = 1 << M;
	int dp[2][maxm];
	memset(dp, 0, sizeof(dp));
	int cur = 0;
	int ans = 0;
	for (int i = 0; i < N; ++i)
	{
		int t;
		scanf("%d", &t);
		memset(dp[!cur], 0, sizeof dp[!cur]);
		for (int i = 0; i < maxm; ++i)
		{
			int c = countbit((i << 1) % maxm);
			if (c < Q)
			{
				dp[!cur][(i << 1 | 1) % maxm] = max(dp[!cur][(i << 1 | 1) % maxm], dp[cur][i] + t);
			}
			dp[!cur][(i << 1) % maxm] = max(dp[!cur][(i << 1) % maxm], dp[cur][i]);
		}
		cur = !cur;
	}
	for (int i = 0; i < maxm; ++i)
	{
		ans = max(ans, dp[cur][i]);
	}
	printf("%d\n", ans);
	return 0;
}
