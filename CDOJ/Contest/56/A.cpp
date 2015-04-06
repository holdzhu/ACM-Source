#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Node
{
	long long w;
	int p;
	bool operator < (const Node rhs) const
	{
		return w > rhs.w || (w == rhs.w && p < rhs.p);
	}
};

int n, m;
vector<pair<int, int> > G[100000];
int s, e, p1, p2, K;
bool vis[100000];

long long solve(int from, int to)
{
	priority_queue<Node> q;
	q.push((Node) {0, from});
	while (!q.empty())
	{
		Node p = q.top();
		q.pop();
		if (p.p == to)
		{
			return p.w;
		}
		vis[p.p] = true;
		for (int i = 0; i < G[p.p].size(); ++i)
		{
			int v = G[p.p][i].first;
			if (!vis[v])
			{
				int w = G[p.p][i].second;
				Node t;
				t.p = v;
				t.w = p.w + w;
				q.push(t);
			}
		}
	}
	return -1;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; ++i)
		{
			G[i].clear();
		}
		map<pair<int, int>, int> roads;
		for (int i = 0; i < m; ++i)
		{
			int x, y, w;
			scanf("%d %d %d", &x, &y, &w);
			if (x > y)
			{
				swap(x, y);
			}
			pair<int, int> p = make_pair(x, y);
			if ((roads.count(p) && roads[p] > w) || !roads.count(p))
			{
				roads[p] = w;
			}
		}
		for (map<pair<int, int>, int>::iterator i = roads.begin(); i != roads.end(); ++i)
		{
			int x = i->first.first;
			int y = i->first.second;
			int w = i->second;
			G[x].push_back(make_pair(y, w));
			G[y].push_back(make_pair(x, w));
		}
		scanf("%d %d %d %d %d", &s, &e, &p1, &p2, &K);
		memset(vis, 0, sizeof(vis));
		vis[p1] = true;
		long long se = solve(s, e);
		memset(vis, 0, sizeof(vis));
		long long sp1 = solve(s, p1);
		memset(vis, 0, sizeof(vis));
		long long p2e = solve(p2, e);
		memset(vis, 0, sizeof(vis));
		long long p1p2 = solve(p1, p2);
		memset(vis, 0, sizeof(vis));
		vis[p1] = true;
		long long _p2e = solve(p2, e);
		long long ans = -1;
		if (se != -1 && p1 != s)
		{
			ans = se;
		}
		if (sp1 != -1 && p1p2 != -1 && p2e != -1 && (ans == -1 || ans > sp1 + p1p2 * (K - 1) + p2e))
		{
			ans = sp1 + p1p2 * (K - 1) + p2e;
		}
		if (sp1 != -1 && _p2e != -1 && (ans == -1 || ans > sp1 + _p2e))
		{
			ans = sp1 + _p2e;
		}
		printf("Case #%d: %lld\n", kase, ans);
	}
	return 0;
}
