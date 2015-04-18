#include <cstdio>
#include <algorithm>

using namespace std;

struct Query
{
	int p, l, r, e, id;
	bool type;
	bool operator < (const Query& rhs) const
	{
		return p < rhs.p || (p == rhs.p && type < rhs.type);
	}
};

#define lchild rt << 1, l, m
#define rchild rt << 1 | 1, m + 1, r

const int n = 100000;
int tree[400011];
bool ans1[200000];
bool ans2[200000];
Query q1[400000];
Query q2[400000];
int pos = 0;

void pushup(int rt)
{
	tree[rt] = min(tree[rt << 1], tree[rt << 1 | 1]);
}

int query(int L, int R, int rt = 1, int l = 1, int r = n)
{
	if (L <= l && r <= R)
	{
		return tree[rt];
	}
	int m = (l + r) >> 1;
	int ret = 1000000000;
	if (L <= m)
	{
		ret = min(ret, query(L, R, lchild));
	}
	if (R > m)
	{
		ret = min(ret, query(L, R, rchild));
	}
	return ret;
}

void update(int x, int value, int rt = 1, int l = 1, int r = n)
{
	if (l == r)
	{
		tree[rt] = value;
		return;
	}
	int m = (l + r) >> 1;
	if (x <= m)
	{
		update(x, value, lchild);
	}
	else
	{
		update(x, value, rchild);
	}
	pushup(rt);
}

void build(int rt = 1, int l = 1, int r = n)
{
	if (l == r)
	{
		tree[rt] = 0;
		return;
	}
	int m = (l + r) >> 1;
	build(lchild);
	build(rchild);
	pushup(rt);
}

int main()
{
	int K, Q;
	scanf("%*d %*d %d %d", &K, &Q);
	for (int i = 0; i < K; ++i)
	{
		scanf("%d %d", &q1[pos].p, &q1[pos].l);
		q2[pos].l = q1[pos].p;
		q2[pos].p = q1[pos].l;
		q1[pos].type = 0;
		q2[pos++].type = 0;
	}
	for (int i = 0; i < Q; ++i)
	{
		scanf("%d %d %d %d", &q1[pos].e, &q1[pos].l, &q1[pos].p, &q1[pos].r);
		q2[pos].p = q1[pos].r;
		q2[pos].l = q1[pos].e;
		q2[pos].r = q1[pos].p;
		q2[pos].e = q1[pos].l;
		q1[pos].id = q2[pos].id = i;
		q1[pos].type = 1;
		q2[pos++].type = 1;
	}
	sort(q1, q1 + pos);
	sort(q2, q2 + pos);
	build();
	for (int i = 0; i < pos; ++i)
	{
		if (q1[i].type)
		{
			if (query(q1[i].l, q1[i].r) >= q1[i].e)
			{
				ans1[q1[i].id] = true;
			}
			else
			{
				ans1[q1[i].id] = false;
			}
		}
		else
		{
			update(q1[i].l, q1[i].p);
		}
	}
	build();
	for (int i = 0; i < pos; ++i)
	{
		if (q2[i].type)
		{
			if (query(q2[i].l, q2[i].r) >= q2[i].e)
			{
				ans2[q2[i].id] = true;
			}
			else
			{
				ans2[q2[i].id] = false;
			}
		}
		else
		{
			update(q2[i].l, q2[i].p);
		}
	}
	for (int i = 0; i < Q; ++i)
	{
		if (ans1[i] || ans2[i])
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}
