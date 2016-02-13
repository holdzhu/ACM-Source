#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<int> G[100];
bool mat[100][100];
bool vis[100];
int tried[100];
int ans[100];
int deg[100];

bool dfsvis[100];

bool dfs(int u, int rt, int fa)
{
	dfsvis[u] = 1;
	for (int i = 0; i < G[u].size(); ++i)
	{
		int v = G[u][i];
		if (v == fa || vis[v])
			continue;
		if (v == rt)
			return false;
		if (!dfsvis[v] && !dfs(v, rt, u))
			return false;
	}
	return true;
}

bool check(int u)
{
	for (int i = 0; i < G[u].size(); ++i)
		if (!vis[G[u][i]] && deg[G[u][i]] == 1 && tried[G[u][i]])
			return false;
	return deg[u] <= 1 || !dfs(u, u, -1);
}

int main()
{
	int tst;
	scanf("%d", &tst);
	while (tst--)
	{
		int m;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; ++i)
		{
			G[i].clear();
			for (int j = 0; j < n; ++j)
				mat[i][j] = 0;
			vis[i] = 0;
			deg[i] = 0;
		}
		while (m--)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			u--;
			v--;
			G[u].push_back(v);
			G[v].push_back(u);
			mat[u][v] = mat[v][u] = 1;
			deg[u]++;
			deg[v]++;
		}
		for (int i = 0, col = 1; i < n; ++i)
		{
			if (!vis[i])
			{
				for (int j = 0; j < n; ++j)
					tried[j] = 0;
				queue<int> q;
				vector<int> s;
				s.push_back(i);
				vis[i] = 1;
				for (int j = 0; j < G[i].size(); ++j)
				{
					if (!vis[G[i][j]])
					{
						q.push(G[i][j]);
						tried[G[i][j]] = 1;
						deg[G[i][j]]--;
					}
				}
				while (!q.empty())
				{
					int u = q.front();
					q.pop();
					int cnt = 0;
					for (int j = 0; j < s.size(); ++j)
						if (mat[u][s[j]])
							cnt++;
					if (cnt == 1 && check(u))
					{
						s.push_back(u);
						vis[u] = 1;
						for (int j = 0; j < G[u].size(); ++j)
						{
							int v = G[u][j];
							if (vis[v])
								continue;
							deg[v]--;
							if (!tried[v])
							{
								q.push(v);
								tried[v] = 1;
							}
						}
					}
				}
				for (int j = 0; j < s.size(); ++j)
					ans[s[j]] = col;
				col++;
			}
		}
		for (int i = 0; i < n; ++i)
			printf("%d ", ans[i]);
		printf("\n");
	}
	return 0;
}
