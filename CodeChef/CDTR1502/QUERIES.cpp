#include <cstdio>
#define lchild rt << 1, l, m
#define rchild rt << 1 | 1, m + 1, r

int N;
int tree[300000];
int lazy[300000];

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

void build(int rt = 1, int l = 1, int r = N)
{
	if (l == r)
	{
		tree[rt] = 0; 
		return;
	}
	int m = (l + r) >> 1;
	build(lchild);
	build(rchild);
	push_up(rt);
}

void update(int L, int R, int delta, int rt = 1, int l = 1, int r = N)
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

int query(int L, int R, int rt = 1, int l = 1, int r = N)
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
	int ret = 0;
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
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int M;
		scanf("%d%d", &N, &M);
		build();
		while (M--)
		{
			int t;
			scanf("%d", &t);
			if (t)
			{
				int a, b;
				scanf("%d%d", &a, &b);
				printf("%d\n", query(a, b));
			}
			else
			{
				int a, b, v;
				scanf("%d%d%d", &a, &b, &v);
				update(a, b, v);
			}
		}
	}
	return 0;
}
