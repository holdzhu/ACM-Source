#include <cstdio>
#include <algorithm>

using namespace std;

long long dp[50010];
int a[50010];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; ++i)
			scanf("%d", &a[i]);
		sort(a, a + N);
		dp[0] = 0;
		long long mx = -1e18;
		for (int i = 0; i < N; ++i)
		{
			mx = max(mx, a[i] - dp[i]);
			dp[i + 1] = mx;
		}
		printf("%I64d\n", dp[N]);
	}
	return 0;
}
