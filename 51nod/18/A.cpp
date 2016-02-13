#include <cstdio>
#include <vector>

using namespace std;

int n;
vector<int> G[100001];
long long dp[100001];
long long ans[100001];
long long cnt[100001];

void dfs(int u, int fa = -1)
{
	cnt[u] = 1;
	dp[u] = 0;
	for (int i = 0; i < G[u].size(); ++i)
	{
		int v = G[u][i];
		if (v == fa)
			continue;
		dfs(v, u);
		cnt[u] += cnt[v];
		dp[u] += dp[v] + cnt[v];
	}
}

void solve(int u, long long sum = 0, int fa = -1)
{
	ans[u] = dp[u] + sum;
	for (int i = 0; i < G[u].size(); ++i)
	{
		int v = G[u][i];
		if (v == fa)
			continue;
		solve(v, sum + dp[u] - dp[v] - cnt[v] + n - cnt[v], u);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1);
	solve(1);
	for (int i = 1; i <= n; ++i)
		printf("%lld\n", ans[i]);
	return 0;
}
