#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

#define lchild rt << 1, l, m
#define rchild rt << 1 | 1, m + 1, r

struct Query
{
	int x, y;
	char c;
};

int N;
long long lazy[1000001];
long long tree[1000001];

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

long long query(int L, int R, int rt = 1, int l = 0, int r = N - 1)
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

void update(int L, int R, long long delta, int rt = 1, int l = 0, int r = N - 1)
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

struct Triangle
{
	int top;
	int left;
	int bottom;
	int right;
};

Triangle tri[200001];
Query Q[200001];
int cnt = 1;
map<int, int> id;
int ls[200001];

int main()
{
	int n, q;
	scanf("%d %d", &n, &q);
	tri[0] = (Triangle){0, 0, n, n};
	memset(tree, 0, sizeof tree);
	memset(lazy, 0, sizeof lazy);
	id[0] = 0;
	id[1] = 0;
	id[n + 1] = 0;
	id[n] = 0;
	for (int i = 0; i < q; ++i)
	{
		scanf("%d %d %c", &Q[i].x, &Q[i].y, &Q[i].c);
		id[Q[i].x] = 0;
		id[Q[i].x + 1] = 0;
		id[Q[i].x - 1] = 0;
	}
	for (map<int, int>::iterator i = id.begin(); i != id.end(); ++i)
	{
		i -> second = N;
		printf("%d %d\n", N, i-> first);
		ls[N++] = i -> first;
	}
	for (int i = 0; i < q; ++i)
	{
		Triangle& t = tri[query(id[Q[i].x], id[Q[i].x])];
		printf("%d\n", query(id[Q[i].x], id[Q[i].x]));
		if (Q[i].c == 'U')
		{
			printf("%d\n", Q[i].y - t.top);
			tri[cnt++] = (Triangle){t.top, Q[i].x};
			printf("%d %d %d %d\n", t.top, Q[i].x, id[Q[i].x], id[n + 1 - t.top]);
			update(id[Q[i].x], id[n + 1 - t.top], cnt - 1 - query(id[Q[i].x + 1], id[Q[i].x + 1]));
		}
		else
		{
			printf("%d\n", Q[i].x - t.left);
			tri[cnt++] = (Triangle){Q[i].y, t.left};
			printf("%d %d %d %d\n", Q[i].y, t.left, id[t.left], id[Q[i].x]);
			update(id[t.left], id[Q[i].x], cnt - 1 - query(id[Q[i].x - 1], id[Q[i].x - 1]));
		}
	}
	return 0;
}
