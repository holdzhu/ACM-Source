#include <cstdio>

#define lchild rt << 1, l, m
#define rchild rt << 1 | 1, m + 1, r

int n;
long long tree[400000];
long long lazy[400000];

void push_up(int rt)
{
	tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
}

void push_down(int rt, int len)
{
	tree[rt << 1] += lazy[rt] * (len - (len >> 1));
	lazy[rt << 1] += lazy[rt];
	tree[rt << 1 | 1] += lazy[rt] * (len >> 1);
	lazy[rt << 1 | 1] += lazy[rt];
	lazy[rt] = 0;
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
	push_up(rt);
}

void update(int L, int R, int delta, int rt = 1, int l = 1, int r = n)
{
	if (L <= l && r <= R)
	{
		tree[rt] += delta * (r - l + 1);
		lazy[rt] += delta;
		return;
	}
	if (lazy[rt])
	{
		push_down(rt, r - l + 1);
	}
	int m = (l + r) >> 1;
	if (L <= m)
	{
		update(L, R, delta, lchild);
	}
	if (R > m)
	{
		update(L, R, delta, rchild);
	}
	push_up(rt);
}

long long query(int L, int R, int rt = 1, int l = 1, int r = n)
{
	if (L <= l && r <= R)
	{
		return tree[rt];
	}
	if (lazy[rt])
	{
		push_down(rt, r - l + 1);
	}
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

int main()
{
	int m;
	scanf("%d %d", &n, &m);
	build();
	while (m--)
	{
		int s;
		scanf("%d", &s);
		if (s)
		{
			int l, r, w;
			scanf("%d %d %d", &l, &r, &w);
			update(l, r, w);
		}
		else
		{
			int l, r;
			scanf("%d %d", &l, &r);
			printf("%lld\n", query(l, r));
		}
	}
	return 0;
}
