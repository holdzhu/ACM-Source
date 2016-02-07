#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int dp[100001];
vector<int> G[100001];
int cnt[100001];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	while (m--)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		if (u < v)
			swap(u, v);
		G[u].push_back(v);
		cnt[u]++;
		cnt[v]++;
	}
	long long ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		dp[i] = 1;
		for (int j = 0; j < G[i].size(); ++j)
		{
			dp[i] = max(dp[i], dp[G[i][j]] + 1);
		}
		ans = max(ans, 1ll * dp[i] * cnt[i]);
	}
	printf("%I64d\n", ans);
	return 0;
}
