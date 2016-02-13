#include <cstdio>
#include <vector>

using namespace std;

vector<int> G[100001];
bool vis[100001];

int dfs(int u)
{
	if (vis[u])
	{
		return 0;
	}
	vis[u] = true;
	int cnt = 1;
	for (int i = 0; i < G[u].size(); ++i)
	{
		int v = G[u][i];
		cnt += dfs(v);
	}
	return cnt;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
		{
			G[i].clear();
			vis[i] = 0;
		}
		for (int i = 0; i < n - 1; ++i)
		{
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			if (w == 0)
			{
				G[u].push_back(v);
				G[v].push_back(u);
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; ++i)
		{
			int cnt = dfs(i);
			if (cnt & 1)
			{
				ans ^= cnt;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}