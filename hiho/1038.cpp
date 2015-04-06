#include <cstdio>
#include <cstring>

inline int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	int a[N];
	int b[N];
	for (int i = 0; i < N; ++i)
	{
		scanf("%d %d", &a[i], &b[i]);
	}
	int dp[M + 1];
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < N; ++i)
	{
		for (int j = M; j >= a[i]; --j)
		{
			dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
		}
	}
	int ans = 0;
	for (int i = 0; i <= M; ++i)
	{
		ans = max(ans, dp[i]);
	}
	printf("%d\n", ans);
	return 0;
}
