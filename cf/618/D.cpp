#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

long long dp[200001][2];

vector<int> G[200001];

void dfs(int u, int fa = -1)
{
	long long sum = 0;
	long long mi1 = 1e12, mi2 = 1e12;
	for (int i = 0; i < G[u].size(); ++i)
	{
		int v = G[u][i];
		if (v == fa)
			continue;
		dfs(v, u);
		sum += dp[v][1] + 1;
		if (dp[v][0] - dp[v][1] - 1 < mi1)
			mi2 = mi1, mi1 = dp[v][0] - dp[v][1] - 1;
		else if (dp[v][0] - dp[v][1] - 1 < mi2)
			mi2 = dp[v][0] - dp[v][1] - 1;
	}
	dp[u][0] = min(sum, sum + mi1);
	dp[u][1] = min(dp[u][0], sum + mi1 + mi2);
}

int main()
{
	int n, x, y;
	scanf("%d %d %d", &n, &x, &y);
	for (int i = 0; i < n - 1; ++i)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	if (x <= y)
	{
		dfs(1);
		printf("%I64d\n", y * dp[1][1] + x * (n - 1 - dp[1][1]));
	}
	else
	{
		if (n == 1)
		{
			printf("0\n");
		}
		else
		{
			bool flag = false;
			for (int i = 1; i <= n; ++i)
				if (G[i].size() == n - 1)
					flag = true;
			printf("%I64d\n", flag ? x + 1ll * y * (n - 2) : 1ll * y * (n - 1));
		}
	}
	return 0;
}
