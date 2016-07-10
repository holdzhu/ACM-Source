#include <climits>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

#define inf 10000000
#define maxn 500

struct edge
{
	int from, to, cap, flow;
	edge() {}
	edge(int from, int to, int cap, int flow)
		: from(from), to(to), cap(cap), flow(flow)
	{
	}
};

struct dinic
{
	int n, m, s, t;
	vector<edge> edges;
	vector<int> G[maxn];
	bool vis[maxn];
	int cur[maxn];
	int d[maxn];

	void addedge(int from, int to, int cap)
	{
		edges.push_back(edge(from, to, cap, 0));
		edges.push_back(edge(to, from, 0, 0));
		m = edges.size();
		G[from].push_back(m - 2);
		G[to].push_back(m - 1);
	}

	bool bfs()
	{
		memset(vis, 0, sizeof(vis));
		queue<int> Q;
		Q.push(s);
		d[s] = 0;
		vis[s] = 1;
		while (!Q.empty())
		{
			int x = Q.front();
			Q.pop();
			for (int i = 0; i < G[x].size(); i++)
			{
				edge &e = edges[G[x][i]];
				if (!vis[e.to] && e.cap > e.flow)
				{
					vis[e.to] = 1;
					d[e.to] = d[x] + 1;
					Q.push(e.to);
				}
			}
		}
		return vis[t];
	}
	int dfs(int x, int a)
	{
		if (x == t || a == 0)
			return a;
		int flow = 0;
		int f;
		for (int &i = cur[x]; i < G[x].size(); i++)
		{
			edge &e = edges[G[x][i]];
			if ((d[e.to] == d[x] + 1) &&
				(f = dfs(e.to, min(e.cap - e.flow, a))) > 0)
			{
				e.flow += f;
				edges[G[x][i] ^ 1].flow -= f;
				flow += f;
				a -= f;
				if (a == 0)
					break;
			}
		}
		return flow;
	}

	int maxflow(int a, int b)
	{
		memset(d, 0, sizeof d);
		s = a;
		t = b;
		int flow = 0;
		while (bfs())
		{
			memset(cur, 0, sizeof(cur));
			flow += dfs(s, inf);
		}
		return flow;
	}
};

dinic din;
int pre[maxn];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		int a, b, mid;
		scanf("%d %d %d", &a, &b, &mid);
		din.edges.clear();
		for (int i = 0; i < maxn; ++i)
			din.G[i].clear();
		for (int i = 0; i < m; ++i)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			din.addedge(x * 2 + 1, y * 2, 1);
			din.addedge(y * 2 + 1, x * 2, 1);
		}
		for (int i = 1; i <= n; ++i)
			din.addedge(i * 2, i * 2 + 1, i == mid ? 2 : 1);
		int s = 0;
		int t = 1;
		din.addedge(s, mid * 2, 2);
		din.addedge(a * 2 + 1, n * 2 + 2, 1);
		din.addedge(b * 2 + 1, n * 2 + 2, 1);
		din.addedge(n * 2 + 2, t, 2);
		din.maxflow(s, t);
		for (int i = 0; i < m; ++i)
		{
			if (din.edges[i * 4].flow)
				pre[din.edges[i * 4].to / 2] = din.edges[i * 4].from / 2;
			if (din.edges[i * 4 + 2].flow)
				pre[din.edges[i * 4 + 2].to / 2] = din.edges[i * 4 + 2].from / 2;
		}
		vector<int> ans1, ans2;
		while (a != mid)
		{
			ans1.push_back(a);
			a = pre[a];
		}
		while (b != mid)
		{
			ans2.push_back(b);
			b = pre[b];
		}
		for (int i = 0; i < ans1.size(); ++i)
			printf("%d ", ans1[i]);
		printf("%d", mid);
		for (int i = (int)ans2.size() - 1; i >= 0; --i)
			printf(" %d", ans2[i]);
		printf("\n");
	}
	return 0;
}
