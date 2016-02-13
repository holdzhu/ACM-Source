#include <cstdio>
#include <vector>

using namespace std;

int mi, cnt;

vector<int> G[500001];

void dfs(int u, int fa = 1, int dep = 1)
{
	if (G[u].size() == 1)
	{
		cnt++;
		if (mi > dep)
			mi = dep;
	}
	for (int v: G[u])
		if (v != fa)
			dfs(v, u, dep + 1);
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int ans = 0;
	for (int v: G[1])
	{
		mi = 1e9;
		cnt = 0;
		dfs(v);
		if (ans < mi + cnt - 1)
			ans = mi + cnt - 1;
	}
	printf("%d\n", ans);
	return 0;
}
