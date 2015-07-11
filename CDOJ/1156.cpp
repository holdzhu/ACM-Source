#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int P[100];
long long dp[100][200001];

long long dfs(long long x, long long k)
{
	if (x < 0)
	{
		return k;
	}
	if (k <= 200000)
	{
		if (dp[x][k] == -1)
		{
			dp[x][k] = dfs(x - 1, k) - dfs(x - 1, k / P[x]);
		}
		return dp[x][k];
	}
	return dfs(x - 1, k) - dfs(x - 1, k / P[x]);
}

int main()
{
	long long N;
	int K;
	scanf("%lld %d", &N, &K);
	for (int i = 0; i < K; ++i)
	{
		scanf("%d", &P[i]);
	}
	memset(dp, -1, sizeof dp);
	sort(P, P + K);
	printf("%lld\n", dfs(K - 1, N));
	return 0;
}
