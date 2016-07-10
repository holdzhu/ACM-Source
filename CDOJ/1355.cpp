#include <cstdio>
#include <algorithm>

using namespace std;

const int inf = 1e9;

int dp[1 << 15];

int main()
{
	for (int i = 1; i < 1 << 15; ++i)
		dp[i] = inf;
	for (int i = 0; i < 15; ++i)
	{
		int D;
		scanf("%d", &D);
		dp[1 << i] = D;
	}
	int N;
	scanf("%d", &N);
	while (N--)
	{
		int A;
		scanf("%d", &A);
		int msk = 0;
		while (A--)
		{
			int t;
			scanf("%d", &t);
			msk |= 1 << --t;
		}
		int C;
		scanf("%d", &C);
		dp[msk] = min(dp[msk], C);
	}
	for (int i = 0; i < 1 << 15; ++i)
		for (int j = i; j; j = (j - 1) & i)
			dp[i] = min(dp[i], dp[j] + dp[i ^ j]);
	printf("%d\n", dp[(1 << 15) - 1]);
	return 0;
}
