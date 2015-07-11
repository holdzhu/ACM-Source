#include <cstdio>
#include <cstring>

#define lchild rt << 1, l, m
#define rchild rt << 1 | 1, m + 1, r

int n;
long long lazy[600001];
long long tree[600001];

void pushup(int rt)
{
	tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
}

void pushdown(int rt, int len)
{
	if (lazy[rt])
	{
		tree[rt << 1] += lazy[rt] * (len - (len >> 1));
		lazy[rt << 1] += lazy[rt];
		tree[rt << 1 | 1] += lazy[rt] * (len >> 1);
		lazy[rt << 1 | 1] += lazy[rt];
		lazy[rt] = 0;
	}
}

long long query(int L, int R, int rt = 1, int l = 1, int r = n)
{
	if (L <= l && r <= R)
	{
		return tree[rt];
	}
	pushdown(rt, r - l + 1);
	int m = (l + r) >> 1;
	long long ret = 0;
	if (L <= m)
	{
		ret += query(L, R, lchild);
	}
	if (R > m)
	{
		ret += query(L, R, rchild);
	}
	return ret;
}

void update(int L, int R, long long delta, int rt = 1, int l = 1, int r = n)
{
	if (L <= l && r <= R)
	{
		tree[rt] += delta * (r - l + 1);
		lazy[rt] += delta;
		return;
	}
	pushdown(rt, r - l + 1);
	int m = (l + r) >> 1;
	if (L <= m)
	{
		update(L, R, delta, lchild);
	}
	if (R > m)
	{
		update(L, R, delta, rchild);
	}
	pushup(rt);
}

void build(int rt = 1, int l = 1, int r = n)
{
	if (l == r)
	{
		scanf("%lld", &tree[rt]);
		return;
	}
	int m = (l + r) >> 1;
	build(lchild);
	build(rchild);
	pushup(rt);
}

int main()
{
	scanf("%d", &n);
	memset(lazy, 0, sizeof lazy);
	memset(tree, 0, sizeof tree);
	build();
	int m;
	scanf("%d", &m);
	while (m--)
	{
		int l, r;
		long long v;
		scanf("%d %d %lld", &l, &r, &v);
		update(l, r, v);
		printf("%lld\n", query(l, r));
	}
	return 0;
}
