#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 4e5;

int c[maxn + 1];
int re[maxn];

long long tree[maxn << 2];
long long lazy[maxn << 2];
int L[maxn], R[maxn];

void push_up(int rt)
{
	tree[rt] = tree[rt << 1] | tree[rt << 1 | 1];
}

void push_down(int rt)
{
	if (lazy[rt])
	{
		tree[rt << 1] = tree[rt << 1 | 1] = lazy[rt << 1] = lazy[rt << 1 | 1] = lazy[rt];
		lazy[rt] = 0;
	}
}

void build(int rt, int l, int r)
{
	if (l >= r)
	{
		tree[rt] = 1ll << c[re[l]];
		return;
	}
	int m = (l + r) >> 1;
	build(rt << 1, l, m);
	build(rt << 1 | 1, m + 1, r);
	push_up(rt);
}

void update(int u, int col, int rt, int l, int r)
{
	if (L[u] <= l && r <= R[u])
	{
		tree[rt] = lazy[rt] = 1ll << col;
		return;
	}
	push_down(rt);
	int m = (l + r) >> 1;
	if (L[u] <= m) update(u, col, rt << 1, l, m);
	if (R[u] > m) update(u, col, rt << 1 | 1, m + 1, r);
	push_up(rt);
}

long long query(int u, int rt, int l, int r)
{
	if (L[u] <= l && r <= R[u])
		return tree[rt];
	push_down(rt);
	long long ret = 0;
	int m = (l + r) >> 1;
	if (L[u] <= m) ret |= query(u, rt << 1, l, m);
	if (R[u] > m) ret |= query(u, rt << 1 | 1, m + 1, r);
	return ret;
}

vector<int> G[maxn + 1];

int tim;
void dfs(int u, int fa = -1)
{
	re[tim] = u;
	L[u] = tim++;
	for (int v: G[u])
		if (v != fa)
			dfs(v, u);
	R[u] = tim - 1;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &c[i]);
	for (int i = 0; i < n - 1; ++i)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1);
	build(1, 0, n - 1);
	while (m--)
	{
		int t;
		scanf("%d", &t);
		if (t == 1)
		{
			int u, col;
			scanf("%d %d", &u, &col);
			update(u, col, 1, 0, n - 1);
		}
		else
		{
			int u;
			scanf("%d", &u);
			printf("%d\n", __builtin_popcountll(query(u, 1, 0, n - 1)));
		}
	}
	return 0;
}
