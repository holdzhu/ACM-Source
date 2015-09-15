#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> G[20000];
int ans = 0;

int dfs(int u, int fa)
{
	int max1 = 0;
	int max2 = 0;
	for (int i = 0; i < G[u].size(); ++i)
	{
		int v = G[u][i];
		if (v != fa)
		{
			int d = dfs(v, u) + 1;
			if (d > max1)
			{
				max2 = max1;
				max1 = d;
			}
			else if (d > max2)
			{
				max2 = d;
			}
		}
	}
	ans = max(ans, max1 + max2);
	return max1;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int u = 1; u < n + m; ++u)
	{
		int v;
		scanf("%d", &v);
		v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(0, -1);
	printf("%d\n", ans);
	return 0;
}
