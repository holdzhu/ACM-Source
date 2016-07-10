#include <cstdio>
#include <vector>
#include <bitset>

using namespace std;

const int maxn = 1e5;

vector<int> G[maxn + 1];

void dfs(int u, int fa)
{
	for (int v: G[u])
	{
		if (v == fa)
			continue;
		dfs(v, u);
	}
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n - 1; ++i)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1, 0);
	return 0;
}
