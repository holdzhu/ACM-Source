#include <algorithm>
#include <cstdio>

using namespace std;

int a[400];
int dp[401][400];
int left[400], right[400];

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
			scanf("%d", &a[j]);
		int sum = 0, mi = 0;
		for (int j = 0; j < M; ++j)
		{
			left[j] = sum - mi;
			mi = min(mi, sum += a[j]);
		}
		sum = mi = 0;
		for (int j = M - 1; j >= 0; --j)
		{
			right[j] = sum - mi;
			mi = min(mi, sum += a[j]);
		}
		int mx = 0;
		for (int j = 0; j < M; ++j)
			dp[i + 1][j]
				= (mx = max(mx, max(dp[i][j], 0) + left[j]) + a[j]) + right[j];
		mx = 0;
		for (int j = M - 1; j >= 0; --j)
			dp[i + 1][j] = max(
				dp[i + 1][j],
				(mx = max(mx, max(dp[i][j], 0) + right[j]) + a[j]) + left[j]);
	}
	int ans = a[0];
	for (int i = 1; i <= N; ++i)
		for (int j = 0; j < M; ++j)
			ans = max(ans, dp[i][j]);
	printf("%d\n", ans);
	return 0;
}
