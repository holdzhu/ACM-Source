#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

vector<int> G[100000];
int key[100000];
int hkey[100000];
bool vis[100000];
bool tryvis[100000];

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; ++i)
		{
			G[i].clear();
		}
		memset(key, -1, sizeof(key));
		memset(hkey, -1, sizeof(hkey));
		memset(vis, 0, sizeof(vis));
		memset(tryvis, 0, sizeof(tryvis));
		for (int i = 0; i < m; ++i)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		int pp;
		scanf("%d", &pp);
		for (int i = 0; i < pp; ++i)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			key[v] = u;
			hkey[u] = v;
		}
		queue<int> q;
		q.push(0);
		while (!q.empty())
		{
			int p = q.front();
			q.pop();
			if (key[p] != -1 && tryvis[key[p]])
			{
				q.push(key[p]);
			}
			vis[p] = true;
			for (int i = 0; i < G[p].size(); ++i)
			{
				int v = G[p][i];
				tryvis[v] = true;
				if (!vis[v])
				{
					if (hkey[v] == -1 || (hkey[v] != -1 && vis[hkey[v]]))
					{
						q.push(v);
					}
				}
			}
		}
		bool flag = true;
		for (int i = 0; i < n; ++i)
		{
			if (!vis[i])
			{
				flag = false;
				break;
			}
		}
		printf("Case #%d: ", kase);
		if (flag)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}
