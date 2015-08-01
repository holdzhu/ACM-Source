#include <cstdio>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector<int> G[100000];
int color[100000];
bool vis[100000];
int cc[3];

bool dfs(int u, int c)
{
	vis[u] = true;
	color[u] = c;
	cc[c]++;
	for (int i = 0; i < G[u].size(); ++i)
	{
		int v = G[u][i];
		if (color[v] == c)
		{
			return false;
		}
		if (color[v] == 0)
		{
			if (!dfs(v, 3 - c))
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; ++i)
		{
			G[i].clear();
		}
		memset(color, 0, sizeof color);
		memset(vis, 0, sizeof vis);
		for (int i = 0; i < m; ++i)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			u--;
			v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		bool flag = true;
		int cnt = 0;
		for (int i = 0; i < n; ++i)
		{
			if (!vis[i])
			{
				cc[1] = cc[2] = 0;
				if (!dfs(i, 1))
				{
					flag = false;
					break;
				}
				cnt += max(cc[1], cc[2]);
			}
		}
		if (flag)
		{
			printf("%d %d\n", cnt, n - cnt);
		}
		else
		{
			printf("Poor wyh\n");
		}
	}
	return 0;
}
