#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;
vector<int> G[101];
int d[101][101];
int w[101];
int v[101];
bool vis[101];
int N, M;

void dfs(int x)
{
	vis[x] = true;
	if (G[x].size() == 1 && v[x] == 0 && x != 1)
	{
		v[x] = 1;
	}
	for (int i = v[x]; i <= M; ++i)
	{
		d[x][i] = w[x];
	}
	for (int i = 0; i < G[x].size(); ++i)
	{
		if (vis[G[x][i]])
		{
			continue;
		}
		dfs(G[x][i]);
		for (int j = M; j >= v[x]; --j)
		{
			for (int k = 1; j - k >= v[x]; ++k)
			{
				if (d[x][j] < d[x][j - k] + d[G[x][i]][k])
				{
					d[x][j] = d[x][j - k] + d[G[x][i]][k];
				}
			}
		}
	}
}

int main()
{
	while (scanf("%d %d", &N, &M) == 2 && N >= 0 && M >= 0)
	{
		for (int i = 1; i <= N; ++i)
		{
			G[i].clear();
			scanf("%d %d", &v[i], &w[i]);
			v[i] = (v[i] + 19) / 20;
		}
		for (int i = 0; i < N - 1; ++i)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		if (M == 0)
		{
			printf("0\n");
			continue;
		}
		memset(d, 0, sizeof(d));
		memset(vis, 0, sizeof(vis));
		dfs(1);
		printf("%d\n", d[1][M]);
	}
	return 0;
}
