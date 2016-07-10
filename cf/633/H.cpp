#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

const int maxn = 30000;
const int blocks = 200;

struct Query
{
	int l, r, id;
	bool operator<(const Query &rhs) const
	{
		return l / blocks < rhs.l / blocks
			   || (l / blocks == rhs.l / blocks && r < rhs.r);
	}
};

int tot;
int mod;
int tree[maxn << 2][2][3];

void build(int rt = 1, int l = 0, int r = tot - 1)
{
	tree[rt][0][0] = tree[rt][1][1] = 1;
	if (l < r)
	{
		int m = (l + r) >> 1;
		build(rt << 1, l, m);
		build(rt << 1 | 1, m + 1, r);
	}
}

void push_up(int rt)
{
	tree[rt][0][2] = tree[rt << 1][0][2] + tree[rt << 1 | 1][0][2];
	if (tree[rt][0][2] >= mod)
		tree[rt][0][2] -= mod;
	tree[rt][1][2] = tree[rt << 1][1][2] + tree[rt << 1 | 1][1][2];
	if (tree[rt][1][2] >= mod)
		tree[rt][1][2] -= mod;
	int a0 = tree[rt][0][0] * tree[rt][0][2] + tree[rt][0][1] * tree[rt][1][2];
	int a1 = tree[rt][1][0] * tree[rt][0][2] + tree[rt][1][1] * tree[rt][1][2];
	tree[rt][0][2] = a0 % mod;
	tree[rt][1][2] = a1 % mod;
}

void update2(int x, int val, int rt = 1, int l = 0, int r = tot - 1)
{
	if (l >= r)
	{
		tree[rt][0][2] = val * tree[rt][0][0] % mod;
		tree[rt][1][2] = val * tree[rt][1][0] % mod;
		return;
	}
	int m = (l + r) >> 1;
	if (x <= m)
		update2(x, val, rt << 1, l, m);
	else
		update2(x, val, rt << 1 | 1, m + 1, r);
	push_up(rt);
}

int tmp[2][2];

void update(int L, int R, int val, bool flag, int rt = 1, int l = 0, int r = tot - 1)
{
	if (L <= l && r <= R)
	{
		if (flag)
			for (int i = 0; i < 3; ++i)
			{
				tree[rt][0][i] = tree[rt][0][i] + tree[rt][1][i];
				tree[rt][1][i] = tree[rt][0][i] - tree[rt][1][i];
				if (tree[rt][0][i] >= mod)
					tree[rt][0][i] -= mod;
			}
		else
			for (int i = 0; i < 3; ++i)
			{
				tree[rt][1][i] = tree[rt][0][i] - tree[rt][1][i];
				tree[rt][0][i] = tree[rt][0][i] - tree[rt][1][i];
				if (tree[rt][1][i] < 0)
					tree[rt][1][i] += mod;
			}
		if (l == L)
			update2(L, val, rt, l, r);
		return;
	}
	int m = (l + r) >> 1;
	if (L <= m)
		update(L, R, val, flag, rt << 1, l, m);
	if (R > m)
		update(L, R, val, flag, rt << 1 | 1, m + 1, r);
	push_up(rt);
}

map<int, int> mp;
int a[maxn];
int val[maxn];
Query query[maxn];
int cnt[maxn];
int ans[maxn];

void add(int x)
{
	if (cnt[x] == 0)
		update(x, tot - 1, val[x], 1);
	cnt[x]++;
}

void sub(int x)
{
	cnt[x]--;
	if (cnt[x] == 0)
		update(x, tot - 1, 0, 0);
}

int main()
{
	int n;
	scanf("%d %d", &n, &mod);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		mp[a[i]] = 0;
	}
	for (auto &p : mp)
		val[p.second = tot++] = p.first;
	for (int i = 1; i <= n; ++i)
		a[i] = mp[a[i]];
	build();
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i)
		scanf("%d %d", &query[i].l, &query[i].r), query[i].id = i;
	sort(query, query + q);
	int l = 1, r = 0;
	for (int i = 0; i < q; ++i)
	{
		while (query[i].l < l)
			add(a[--l]);
		while (query[i].l > l)
			sub(a[l++]);
		while (query[i].r < r)
			sub(a[r--]);
		while (query[i].r > r)
			add(a[++r]);
		ans[query[i].id] = tree[1][1][2];
	}
	for (int i = 0; i < q; ++i)
		printf("%d\n", ans[i]);
	return 0;
}
