#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 1000000000
#define maxn 1002

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

int l[300];
int c[300];
vector<int> p;

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &l[i]);
		int t = l[i];
		for (int j = 2; j * j <= t; ++j)
		{
			if (t % j == 0)
			{
				p.push_back(j);
				while (t % j == 0)
				{
					t /= j;
				}
			}
		}
		if (t > 1)
		{
			p.push_back(t);
		}
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &c[i]);
	}
	sort(p.begin(), p.end());
	p.erase(unique(p.begin(), p.end()), p.end());
	MCMF mcmf;
	mcmf.init()
	return 0;
}
