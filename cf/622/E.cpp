#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int cnt;
vector<int> G[500001];
int a[500001];

void dfs(int u, int fa = 1, int dep = 1)
{
	if (G[u].size() == 1)
		a[cnt++] = dep;
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
		cnt = 0;
		dfs(v);
		sort(a, a + cnt);
		for (int i = 0; i < cnt; ++i)
			ans = max(ans, a[i] + cnt - 1 - i);
	}
	printf("%d\n", ans);
	return 0;
}
