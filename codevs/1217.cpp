#include <cstdio>
#include <algorithm>

using namespace std;

int a[1000000];
int tree[4000000];
int lazy[4000000];

void build(int rt, int l, int r)
{
	if (l >= r)
		tree[rt] = a[l];
	else
	{
		int m = (l + r) >> 1;
		build(rt << 1, l, m);
		build(rt << 1 | 1, m + 1, r);
		tree[rt] = min(tree[rt << 1], tree[rt << 1 | 1]);
	}
}

void update(int L, int R, int val, int rt, int l, int r)
{
	if (L <= l && r <= R)
	{
		tree[rt] += val;
		lazy[rt] += val;
		return;
	}
	if (lazy[rt])
	{
		tree[rt << 1] += lazy[rt];
		lazy[rt << 1] += lazy[rt];
		tree[rt << 1 | 1] += lazy[rt];
		lazy[rt << 1 | 1] += lazy[rt];
		lazy[rt] = 0;
	}
	int m = (l + r) >> 1;
	if (L <= m)
		update(L, R, val, rt << 1, l, m);
	if (R >= m + 1)
		update(L, R, val, rt << 1 | 1, m + 1, r);
	tree[rt] = min(tree[rt << 1], tree[rt << 1 | 1]);
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	build(1, 0, n - 1);
	bool flag = true;
	for (int i = 0; i < m; ++i)
	{
		int d, s, t;
		scanf("%d %d %d", &d, &s, &t);
		update(s - 1, t - 1, -d, 1, 0, n - 1);
		if (tree[1] < 0)
		{
			flag = false;
			printf("-1\n%d\n", i + 1);
			break;
		}
	}
	if (flag)
		puts("0");
	return 0;
}
