#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

struct Edge
{
	int from, to, cap, flow;
};

const int maxn = 1e3;
const int INF  = 1e9;

int n, m;
vector<Edge> edges;
vector<int> G[maxn];
bool vis[maxn];
int d[maxn];
int cur[maxn];

void AddEdge(int from, int to, int cap)
{
	edges.push_back((Edge){from, to, cap, 0});
	edges.push_back((Edge){to, from, 0, 0});
	int m = edges.size();
	G[from].push_back(m - 2);
	G[to].push_back(m - 1);
}

bool BFS(int s, int t)
{
	memset(vis, 0, sizeof vis);
	queue<int> Q;
	Q.push(s);
	d[s]   = 0;
	vis[s] = 1;
	while (!Q.empty())
	{
		int x = Q.front();
		Q.pop();
		for (int v : G[x])
		{
			Edge &e = edges[v];
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

int DFS(int x, int a, int t)
{
	if (x == t || a == 0)
		return a;
	int flow = 0, f;
	for (int &i = cur[x]; i < G[x].size(); ++i)
	{
		Edge &e = edges[G[x][i]];
		if (d[x] + 1 == d[e.to]
			&& (f = DFS(e.to, min(a, e.cap - e.flow), t)) > 0)
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

int Maxflow(int s, int t)
{
	int flow = 0;
	while (BFS(s, t))
	{
		memset(cur, 0, sizeof cur);
		flow += DFS(s, INF, t);
	}
	return flow;
}

bool dbl[maxn];
int Y[maxn];

int main()
{
	int N, M, P;
	scanf("%d %d %d", &N, &M, &P);
	int sum = 0;
	int S   = N + M + P;
	int T = S + 1;
	for (int i = 0; i < N; ++i)
	{
		int X, K;
		scanf("%d %d", &X, &K);
		sum += X;
		AddEdge(i, T, X);
		while (K--)
		{
			int I;
			scanf("%d", &I);
			AddEdge(N + I - 1, i, INF);
		}
	}
	for (int i = 0; i < M; ++i)
		scanf("%d", &Y[i]);
	for (int i = 0; i < P; ++i)
	{
		int J1, J2, D;
		scanf("%d %d %d", &J1, &J2, &D);
		dbl[J1 - 1] = dbl[J2 - 1] = 1;
		AddEdge(S, N + M + i, D);
		AddEdge(N + M + i, N + J1 - 1, Y[J1 - 1]);
		AddEdge(N + M + i, N + J2 - 1, Y[J2 - 1]);
	}
	for (int i = 0; i < M; ++i)
		if (!dbl[i])
			AddEdge(S, N + i, Y[i]);
	printf("%d\n", sum - Maxflow(S, T));
	return 0;
}
