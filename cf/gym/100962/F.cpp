#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

struct Query
{
	int l, r, id;
};

const int len = 400;
const int maxn = 1e5;
vector<pair<int, int> > G[maxn + 1];
int fa[maxn + 1];
bool inner[maxn + 1];
int x[maxn + 1];
int dep[maxn + 1];
int tim[maxn + 1];
int cnt[maxn + 1];
int ans[maxn + 1];
int blk[(maxn + 2 + len) / len];
Query qry[maxn + 1];

bool operator<(const Query &lhs, const Query &rhs)
{
	return tim[lhs.l] / len < tim[rhs.l] / len
		   || (tim[lhs.l] / len == tim[rhs.l] / len && tim[lhs.r] < tim[rhs.r]);
}

void dfs(int u = 1, int f = 0)
{
	static int cur = 0;
	tim[u] = cur++;
	for (auto &p : G[u])
	{
		int v = p.first;
		if (v == f)
			continue;
		fa[v] = u;
		x[v] = p.second;
		dep[v] = dep[u] + 1;
		dfs(v, u);
	}
}

void modify(int val, int delta)
{
	int idx = val / len;
	if (cnt[val] == 0)
		blk[idx]++;
	cnt[val] += delta;
	if (cnt[val] == 0)
		blk[idx]--;
}

void move_up(int &u)
{
	if (inner[u])
		modify(x[u], -1);
	else
		modify(x[u], 1);
	inner[u] = !inner[u];
	u = fa[u];
}

void move(int u, int v)
{
	while (dep[u] > dep[v])
		move_up(u);
	while (dep[v] > dep[u])
		move_up(v);
	while (u != v)
		move_up(u), move_up(v);
}

int main()
{
	int n, q;
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n - 1; ++i)
	{
		int u, v, x;
		scanf("%d %d %d", &u, &v, &x);
		x = min(x, n);
		G[u].push_back({v, x});
		G[v].push_back({u, x});
	}
	dfs();
	for (int i = 1; i <= q; ++i)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		qry[i] = {a, b, i};
	}
	sort(qry + 1, qry + q + 1);
	qry[0] = {1, 1, -1};
	for (int i = 1; i <= q; ++i)
	{
		move(qry[i - 1].l, qry[i].l);
		move(qry[i - 1].r, qry[i].r);
		for (int j = 0; ; ++j)
			if (blk[j] != len)
			{
				for (int k = len * j; ; ++k)
					if (cnt[k] == 0)
					{
						ans[qry[i].id] = k;
						break;
					}
				break;
			}
	}
	for (int i = 1; i <= q; ++i)
		printf("%d\n", ans[i]);
	return 0;
}
