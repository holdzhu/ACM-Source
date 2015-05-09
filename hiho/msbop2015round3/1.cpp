#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> G[100000];
long long w[100000];

long long ans;

long long dfs(int x, int fa, int dis)
{
	long long sum = w[x];
	for (int i = 0; i < G[x].size(); ++i)
	{
		if (G[x][i] != fa)
		{
			sum += dfs(G[x][i], x, dis + 1);
		}
	}
	ans = max(ans, sum + 1 - dis);
	return sum;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 0; kase < T; ++kase)
	{
		int n, x;
		scanf("%d %d", &n, &x);
		x--;
		ans = 0;
		for (int i = 0; i < n; ++i)
		{
			G[i].clear();
		}
		for (int i = 0; i < n - 1; ++i)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			u--;
			v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for (int i = 0; i < n; ++i)
		{
			scanf("%lld", &w[i]);
		}
		for (int i = 0; i < G[x].size(); ++i)
		{
			dfs(G[x][i], x, 1);
		}
		printf("Case #%d: %lld\n", kase + 1, ans);
	}
	return 0;
}
