#include <cstdio>
#include <cstring>
#include <vector>
#include <functional>
#include <algorithm>
#include <set>

using namespace std;

vector<int> G[100000];
vector<int> W[100000];
int dis[100000];
pair<int, int> rmq[20][200000];
int cid;
int in[100000];
int prelog[100000];
int n, q;
set<pair<int, int> > vertex;
bool vis[100000];

void dfs(int u, int fa, int d, int de)
{
	dis[u] = d;
	rmq[0][cid].first = de;
	rmq[0][cid].second = u;
	in[u] = cid++;
	for (int i = 0; i < G[u].size(); ++i)
	{
		int v = G[u][i];
		if (v == fa)
		{
			continue;
		}
		dfs(v, u, d + W[u][i], de + 1);
		rmq[0][cid].first = de;
		rmq[0][cid++].second = u;
	}
}

int lca(int u, int v)
{
	if (in[u] > in[v])
	{
		swap(u, v);
	}
	int t;
	for (t = 1; 1 << t <= in[v] - in[u]; ++t);
	return min(rmq[t - 1][in[u]], rmq[t - 1][in[v] + 1 - (1 << (t - 1))]).second;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		scanf("%d %d", &n, &q);
		for (int i = 0; i < n; ++i)
		{
			G[i].clear();
			W[i].clear();
		}
		for (int i = 0; i < n - 1; ++i)
		{
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			u--;
			v--;
			G[u].push_back(v);
			W[u].push_back(w);
			G[v].push_back(u);
			W[v].push_back(w);
		}
		cid = 0;
		dfs(0, -1, 0, 0);
		for (int i = 1; (1 << i) <= cid; ++i)
		{
			for (int j = 0; j <= cid - (1 << i); ++j)
			{
				rmq[i][j] = min(rmq[i - 1][j], rmq[i - 1][j + (1 << (i - 1))]);
			}
		}
		long long ans = 0;
		vertex.clear();
		memset(vis, 0, sizeof vis);
		printf("Case #%d:\n", kase);
		while (q--)
		{
			int c, u;
			scanf("%d %d", &c, &u);
			u--;
			pair<int, int> p = make_pair(in[u], u);
			if (c == 1 && !vis[u])
			{
				vis[u] = true;
				if (vertex.size() > 0)
				{
					set<pair<int, int> >::iterator it = vertex.lower_bound(p);
					int x, y;
					if (it == vertex.begin() || it == vertex.end())
					{
						x = vertex.begin()->second;
						y = (--vertex.end())->second;
					}
					else
					{
						x = it->second;
						y = (--it)->second;
					}
					ans += dis[u] - dis[lca(x, u)] - dis[lca(y, u)] + dis[lca(x, y)];
				}
				vertex.insert(p);
			}
			else if (c == 2 && vis[u])
			{
				vis[u] = false;
				vertex.erase(p);
				if (vertex.size() > 0)
				{
					set<pair<int, int> >::iterator it = vertex.lower_bound(p);
					int x, y;
					if (it == vertex.begin() || it == vertex.end())
					{
						x = vertex.begin()->second;
						y = (--vertex.end())->second;
					}
					else
					{
						x = it->second;
						y = (--it)->second;
					}
					ans -= dis[u] - dis[lca(x, u)] - dis[lca(y, u)] + dis[lca(x, y)];
				}
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}
