#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

#define INF 1000000000
#define maxn 10002

struct Edge
{
	int from, to, cap, flow, cost;
	Edge(int u, int v, int c, int f, int w) : from(u), to(v), cap(c), flow(f), cost(w) {}
};

struct MCMF
{
	int n, m;
	vector<Edge> edges;
	vector<int> G[maxn];
	int inq[maxn];
	int d[maxn];
	int p[maxn];
	int a[maxn];

	void init(int n)
	{
		this->n = n;
		for (int i = 0; i < n; ++i)
		{
			G[i].clear();
		}
		edges.clear();
	}

	void AddEdge(int from, int to, int cap, int cost)
	{
		edges.push_back(Edge(from, to, cap, 0, cost));
		edges.push_back(Edge(to, from, 0, 0, -cost));
		m = edges.size();
		G[from].push_back(m - 2);
		G[to].push_back(m - 1);
	}

	bool BellmanFord(int s, int t, int & cost)
	{
		for (int i = 0; i < n; ++i)
		{
			d[i] = INF;
		}
		memset(inq, 0, sizeof(inq));
		d[s] = 0;
		inq[s] = 1;
		p[s] = 0;
		a[s] = INF;
		queue<int> Q;
		Q.push(s);
		while (!Q.empty())
		{
			int u = Q.front();
			Q.pop();
			inq[u] = 0;
			for (int i = 0; i < G[u].size(); ++i)
			{
				Edge & e = edges[G[u][i]];
				if (e.cap > e.flow && d[e.to] > d[u] + e.cost)
				{
					d[e.to] = d[u] + e.cost;
					p[e.to] = G[u][i];
					a[e.to] = min(a[u], e.cap - e.flow);
					if (!inq[e.to])
					{
						Q.push(e.to);
						inq[e.to] = 1;
					}
				}
			}
		}
		if (d[t] == INF)
		{
			return false;
		}
		cost += d[t] * a[t];
		for (int u = t; u != s; u = edges[p[u]].from)
		{
			edges[p[u]].flow += a[t];
			edges[p[u] ^ 1].flow -= a[t];
		}
		return true;
	}

	int MincostMaxflow(int s, int t)
	{
		int cost = 0;
		while (BellmanFord(s, t, cost));
		return cost;
	}
};

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	MCMF mcmf;
	mcmf.init(n * 7 + 2);
	int s = n * 7;
	int t = n * 7 + 1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 7; ++j)
		{
			int a;
			scanf("%d", &a);
			mcmf.AddEdge(s, i * 7 + j, a, 0);
		}
		for (int j = 0; j < 7; ++j)
		{
			int b;
			scanf("%d", &b);
			mcmf.AddEdge(i * 7 + j, t, b, 0);
		}
		int v, w;
		scanf("%d %d", &v, &w);
		for (int j = 0; j < 7; ++j)
		{
			mcmf.AddEdge(i * 7 + j, i * 7 + (j + 1) % 7, v, w);
		}
	}
	for (int i = 0; i < m; ++i)
	{
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		u--;
		v--;
		for (int j = 0; j < 7; ++j)
		{
			mcmf.AddEdge(u * 7 + j, v * 7 + j, INF, w);
			mcmf.AddEdge(v * 7 + j, u * 7 + j, INF, w);
		}
	}
	printf("%d\n", mcmf.MincostMaxflow(s, t));
	return 0;
}
