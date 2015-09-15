#include <cstdio>
#include <cstring>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

vector<int> G[100000];
vector<pair<int, pair<int, int> > > chains[100000];
pair<int, int> rmq[20][200000];
int cid;
int in[100000];
int n, m;


int lowbit(int u)
{
	return u & (-u);
}

void update(int u, int delta, int *array)
{
	while (u <= cid)
	{
		array[u] += delta;
		u += lowbit(u);
	}
}

int query(int u, int *array)
{
	int rnt = 0;
	while (u)
	{
		rnt += array[u];
		u -= lowbit(u);
	}
	return rnt;
}

void dfs(int u, int fa, int de)
{
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
		dfs(v, u, de + 1);
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
	while (T--)
	{
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; ++i)
		{
			G[i].clear();
		}
		for (int i = 0; i < n - 1; ++i)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			u--;
			v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		cid = 0;
		dfs(0, -1, 0);
		for (int i = 1; (1 << i) <= cid; ++i)
		{
			for (int j = 0; j <= cid - (1 << i); ++j)
			{
				rmq[i][j] = min(rmq[i - 1][j], rmq[i - 1][j + (1 << (i - 1))]);
			}
		}
		for (int i = 0; i < m; ++i)
		{
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			int p = lca(u, v);
			chains[p].push_back(make_pair(w, make_pair(u, v)));
		}
	}
	return 0;
}
