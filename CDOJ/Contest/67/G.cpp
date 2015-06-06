#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

#define INF 2100000000
#define maxn 50000

using namespace std;

struct Edge
{
	int from, to, cap, flow;
	Edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
};

struct EdmondsKarp
{
	int m;
	vector<Edge> edges;
	vector<int> G[maxn];
	int a[maxn];
	int p[maxn];

	void init(int n)
	{
		for (int i = 0; i < n; ++i)
		{
			G[i].clear();
		}
		edges.clear();
	}

	void AddEdge(int from, int to, int cap)
	{
		edges.push_back(Edge(from, to, cap, 0));
		edges.push_back(Edge(to, from, 0, 0));
		m = edges.size();
		G[from].push_back(m - 2);
		G[to].push_back(m - 1);
	}

	int Maxflow(int s, int t)
	{
		int flow = 0;
		while (true)
		{
			memset(a, 0, sizeof a);
			queue<int> Q;
			Q.push(s);
			a[s] = INF;
			while (!Q.empty())
			{
				int x = Q.front();
				Q.pop();
				for (int i = 0; i < G[x].size(); ++i)
				{
					Edge& e = edges[G[x][i]];
					if (!a[e.to] && e.cap > e.flow)
					{
						p[e.to] = G[x][i];
						a[e.to] = min(a[x], e.cap - e.flow);
						Q.push(e.to);
					}
				}
				if (a[t])
				{
					break;
				}
			}
			if (!a[t])
			{
				break;
			}
			for (int u = t; u != s; u = edges[p[u]].from)
			{
				edges[p[u]].flow += a[t];
				edges[p[u] ^ 1].flow -= a[t];
			}
			flow += a[t];
		}
		return flow;
	}
};

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	EdmondsKarp ek;
	ek.init(N + M + 2);
	int s = N + M;
	int t = s + 1;
	for (int i = 0; i < N; ++i)
	{
		ek.AddEdge(s, i, 1);
	}
	for (int i = 0; i < M; ++i)
	{
		ek.AddEdge(N + i, t, 1);
	}
	for (int i = 0; i < N; ++i)
	{
		int s;
		scanf("%d", &s);
		for (int j = 0; j < s; ++j)
		{
			int v;
			scanf("%d", &v);
			ek.AddEdge(i, N + v - 1, 1);
		}
	}
	printf("%d\n", ek.Maxflow(s, t));
	return 0;
}
