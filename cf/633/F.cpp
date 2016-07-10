#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> G[100001];
int a[100001];
long long dp[100001][4];

void dfs(int u, int fa)
{
	long long mx[3] = {0}, mx1 = 0;
	for (int v: G[u])
	{
		if (v == fa)
			continue;
		dfs(v, u);
		if (dp[v][0] > mx[0])
			mx[2] = mx[1], mx[1] = mx[0], mx[0] = dp[v][0];
		else if (dp[v][0] > mx[1])
			mx[2] = mx[1], mx[1] = dp[v][0];
		else if (dp[v][0] > mx[2])
			mx[2] = dp[v][0];
		dp[u][3] = max(dp[u][3], mx1 + dp[v][1]);
		mx1 = max(mx1, dp[v][1]);
	}
	dp[u][0] = mx[0] + a[u];
	dp[u][1] = max(mx[0] + mx[1] + a[u], mx1);
	for (int v: G[u])
	{
		if (v == fa)
			continue;
		long long t1 = dp[v][0] > mx[1] ? mx[1] : mx[0], t2 = dp[v][0] < mx[1] ? mx[1] : mx[2];
		dp[u][2] = max({dp[u][2], dp[v][2] + a[u], t1 + dp[v][1] + a[u]});
		dp[u][3] = max({dp[u][3], dp[v][3], dp[v][2] + a[u] + t1, t1 + t2 + dp[v][1] + a[u]});
	}
	for (int i = 0; i < 3; ++i)
		dp[u][i + 1] = max(dp[u][i + 1], dp[u][i]);
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int i = 0; i < n - 1; ++i)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1, 0);
	printf("%I64d\n", dp[1][3]);
	return 0;
}