#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int n;
vector<int> Gid[100];
vector<int> G[100];
int ans[100][99];

void dfs(int u, int fa = -1)
{
	for (int i = 0; i < G[u].size(); ++i)
	{
		int v = G[u][i];
		if (v == fa)
		{
			continue;
		}
		memcpy(ans[v], ans[u], sizeof ans[u]);
		ans[v][Gid[u][i]]++;
		dfs(v, u);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		Gid[u].push_back(i);
		G[v].push_back(u);
		Gid[v].push_back(i);
	}
	memset(ans, 0, sizeof ans);
	dfs(0);
	printf("%d\n", n - 1);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n - 1; ++j)
		{
			if (j)
			{
				printf(" ");
			}
			printf("%d", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}
