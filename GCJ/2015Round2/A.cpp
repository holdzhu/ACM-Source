#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

#define INF 1000000000
#define maxn 20002

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
	int flow;

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
		flow += a[t];
		return true;
	}

	int MincostMaxflow(int s, int t)
	{
		flow = 0;
		int cost = 0;
		while (BellmanFord(s, t, cost));
		return cost;
	}
};

int R, C;
char ma[100][101];
const int d[] = {0, 1, 0, -1, 1, 0, -1, 0};
const char ch[] = {'>', '<', 'v', '^'};

inline bool isvaild(int x, int y)
{
	return x >= 0 && y >= 0 && x < R && y < C;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 0; kase < T; ++kase)
	{
		scanf("%d %d", &R, &C);
		MCMF mcmf;
		mcmf.init(R * C * 2 + 2);
		int s = R * C * 2;
		int t = R * C * 2 + 1;
		for (int i = 0; i < R; ++i)
		{
			scanf("%s", ma[i]);
		}
		int cnt = 0;
		for (int i = 0; i < R; ++i)
		{
			for (int j = 0; j < C; ++j)
			{
				int id = i * C + j;
				if (ma[i][j] != '.')
				{
					cnt++;
					mcmf.AddEdge(s, id, 1, 0);
					mcmf.AddEdge(R * C + id, t, INF, 0);
					for (int k = 0; k < 4; ++k)
					{
						int dx = d[k * 2];
						int dy = d[k * 2 + 1];
						int x = i + dx;
						int y = j + dy;
						while (isvaild(x, y) && ma[x][y] == '.')
						{
							x += dx;
							y += dy;
						}
						if (isvaild(x, y))
						{
							mcmf.AddEdge(id, R * C + x * C + y, 1, ch[k] != ma[i][j]);
						}
					}
				}
			}
		}
		int ans = mcmf.MincostMaxflow(s, t);
		printf("Case #%d: ", kase + 1);
		if (mcmf.flow != cnt)
		{
			printf("IMPOSSIBLE\n");
		}
		else
		{
			printf("%d\n", ans);
		}
	}
	return 0;
}
