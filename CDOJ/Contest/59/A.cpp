#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define lchild rt << 1, l, m
#define rchild rt << 1 | 1, m + 1, r

struct cmd
{
	int type, l, r, v;
};

int n;
long long lazy[1000001];
long long tree[1000001];
int num[1000000];
int pnum = 0;
cmd cmds[1000000];

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

long long query(int L, int R, int rt = 1, int l = 0, int r = n - 1)
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

void update(int L, int R, long long delta, int rt = 1, int l = 0, int r = n - 1)
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

int main()
{
	scanf("%d", &n);
	memset(lazy, 0, sizeof lazy);
	memset(tree, 0, sizeof tree);
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; ++i)
	{
		int type;
		scanf("%d", &type);
		if (type == 0)
		{
			int l, r, v;
			scanf("%d %d %d", &l, &r, &v);
			cmds[i] = (cmd){type, l, r, v};
			num[pnum++] = l;
			num[pnum++] = r;
		}
		else
		{
			int x;
			scanf("%d", &x);
			cmds[i] = (cmd){type, x, 0, 0};
			num[pnum++] = x;
		}
	}
	sort(num, num + pnum);
	n = unique(num, num + pnum) - num;
	for (int i = 0; i < m; ++i)
	{
		if (cmds[i].type == 0)
		{
			int l = lower_bound(num, num + n, cmds[i].l) - num;
			int r = lower_bound(num, num + n, cmds[i].r) - num;
			update(l, r, cmds[i].v);
		}
		else
		{
			int x = lower_bound(num, num + n, cmds[i].l) - num;
			printf("%lld\n", query(x, x));
		}
	}
	return 0;
}
