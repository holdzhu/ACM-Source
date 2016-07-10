#include <cstdio>
#include <cstring>
#include <functional>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

const int maxn = 1 << 16;
const int maxm = 1e4;
const int maxk = 10;
const int maxnode = maxn * 4 + maxm * 2;

int n, m, k;
vector<pair<int, int>> G[maxnode];
int dis[maxnode][maxk + 1];
bool vis[maxnode][maxk + 1];

inline int idx(int type, int id) { return type * maxn * 2 + id; }

inline void addEdge(int x, int u, int y, int v, int w = 0)
{
	G[idx(x, u)].push_back({idx(y, v), w});
}

inline void range(int l, int r, const function<void(int)> &func)
{
	for (l += maxn - 1, r += maxn + 1; l ^ r ^ 1; l >>= 1, r >>= 1)
	{
		if (~l & 1)
			func(l ^ 1);
		if (r & 1)
			func(r ^ 1);
	}
}

int dijkstra(int s, int t)
{
	memset(dis, -1, sizeof dis);
	priority_queue<tuple<int, int, int>> pq;
	pq.push(make_tuple(0, s, 0));
	dis[s][0] = 0;
	while (pq.size())
	{
		int u = get<1>(pq.top());
		int step = get<2>(pq.top());
		pq.pop();
		if (vis[u][step])
			continue;
		vis[u][step] = true;
		if (u == t)
			break;
		for (const auto &p : G[u])
		{
			int v = p.first;
			int w = p.second;
			for (int i = 0; i <= k; ++i)
			{
				if (dis[v][i] == -1 || dis[v][i] > dis[u][i] + w)
					pq.push(make_tuple(-(dis[v][i] = dis[u][i] + w), v, i));
				if (i < k && (dis[v][i + 1] == -1 || dis[v][i + 1] > dis[u][i]))
					pq.push(make_tuple(-(dis[v][i + 1] = dis[u][i]), v, i + 1));
			}
		}
	}
	int ret = -1;
	for (int i = 0; i <= k; ++i)
		if (vis[t][i] && (ret == -1 || ret > dis[t][i]))
			ret = dis[t][i];
	return ret;
}

int main()
{
	for (int i = 2; i < maxn * 2; ++i)
	{
		addEdge(0, i, 0, i >> 1);
		addEdge(1, i >> 1, 1, i);
	}
	for (int i = maxn; i < maxn * 2; ++i)
		addEdge(1, i, 0, i);
	scanf("%*d %d %d %d", &n, &m, &k);
	for (int i = 0; i < m; ++i)
	{
		int a, b, c, d, w;
		scanf("%d %d %d %d %d", &a, &b, &c, &d, &w);
		range(a, b, [i, w](int u) {
			addEdge(0, u, 2, i << 1);
			addEdge(2, i << 1 | 1, 1, u, w);
		});
		range(c, d, [i, w](int u) {
			addEdge(0, u, 2, i << 1 | 1);
			addEdge(2, i << 1, 1, u, w);
		});
	}
	int ans = dijkstra(maxn + 1, maxn + n);
	if (ans == -1)
		puts("CreationAugust is a sb!");
	else
		printf("%d\n", ans);
	return 0;
}
