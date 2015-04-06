#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

struct Edge
{
	int from, to, cost;
	Edge(int u, int v, int c) : from(u), to(v), cost(c) {}
};

int main()
{
	int N, M;
	while (scanf("%d %d", &N, &M) == 2 && N && M)
	{
		vector<Edge> edges;
		vector<int> G[100];
		priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
		for (int i = 0; i < M; ++i)
		{
			int A, B, C;
			scanf("%d %d %d", &A, &B, &C);
			edges.push_back(Edge(A - 1, B - 1, C));
			edges.push_back(Edge(B - 1, A - 1, C));
			G[A - 1].push_back(i * 2);
			G[B - 1].push_back(i * 2 + 1);
		}
		pq.push(make_pair(0, 0));
		bool vis[N];
		memset(vis, 0, sizeof(vis));
		while (!pq.empty())
		{
			pair<int, int> p = pq.top();
			pq.pop();
			if (vis[p.second])
			{
				continue;
			}
			if (p.second == N - 1)
			{
				printf("%d\n", p.first);
				break;
			}
			for (int i = 0; i < G[p.second].size(); ++i)
			{
				if (!vis[edges[G[p.second][i]].to])
				{
					pq.push(make_pair(p.first + edges[G[p.second][i]].cost, edges[G[p.second][i]].to));
				}
			}
			vis[p.second] = true;
		}
	}
	return 0;
}
