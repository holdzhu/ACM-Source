#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> G[10000];
bool vis[10000];
int sum = 0;

void dfs(int u = 0, int fa = -1)
{
	sum++;
	vis[u] = true;
	for (int i = 0; i < G[u].size(); ++i)
	{
		int v = G[u][i];
		if (!vis[v])
		{
			dfs(v, u);
		}
	}
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	int odd = 0;
	for (int i = 0; i < M; ++i)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		u--;
		v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	memset(vis, 0, sizeof vis);
	dfs();
	for (int i = 0; i < N; ++i)
	{
		if (G[i].size() % 2 == 1)
		{
			odd++;
		}
	}
	if (N == sum && odd <= 2)
	{
		printf("Full\n");
	}
	else
	{
		printf("Part\n");
	}
	return 0;
}
