#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

#define INF 1000000000
#define maxn 1002

using namespace std;

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
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		char s[m + 1];
		int r[n], c[m];
		int count = 0;
		memset(r, 0, sizeof(r));
		memset(c, 0, sizeof(c));
		for (int i = 0; i < n; ++i)
		{
			scanf("%s", s);
			for (int j = 0; j < m; ++j)
			{
				if (s[j] == '1')
				{
					r[i]++;
					c[j]++;
					count++;
				}
			}
		}
		printf("Case %d: ", kase);
		if (count % n == 0 || count % m == 0)
		{
			MCMF mcmf;
			int ans = 0;
			if (count % n == 0)
			{
				int a = count / n;
				mcmf.init(n + 2);
				int s = n;
				int t = n + 1;
				for (int i = 0; i < n; ++i)
				{
					mcmf.AddEdge(s, i, r[i], 0);
					mcmf.AddEdge(i, t, a, 0);
					mcmf.AddEdge(i, (i + 1) % n, INF, 1);
					mcmf.AddEdge((i + 1) % n, i, INF, 1);
				}
				ans += mcmf.MincostMaxflow(s, t);
			}
			if (count % m == 0)
			{
				int a = count / m;
				mcmf.init(m + 2);
				int s = m;
				int t = m + 1;
				for (int i = 0; i < m; ++i)
				{
					mcmf.AddEdge(s, i, c[i], 0);
					mcmf.AddEdge(i, t, a, 0);
					mcmf.AddEdge(i, (i + 1) % m, INF, 1);
					mcmf.AddEdge((i + 1) % m, i, INF, 1);
				}
				ans += mcmf.MincostMaxflow(s, t);
			}
			if (count % n == 0 && count % m == 0)
			{
				printf("both ");
			}
			else if (count % n == 0)
			{
				printf("row ");
			}
			else
			{
				printf("column ");
			}
			printf("%d\n", ans);
		}
		else
		{
			printf("impossible\n");
		}
	}
	return 0;
}
