#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

#define lchild rt << 1, l, m
#define rchild rt << 1 | 1, m + 1, r

struct Query
{
	char type;
	int l, r;
	int x[5], y[5];
};

double lazya[800005];
double lazyk[800005];
double tree[800005];
int x[225005];
int n;
Query q[25005];
map<int, int> id;

void pushup(int rt)
{
	tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
	tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
}

void pushdown(int rt, int l, int r)
{
	int m = (l + r) >> 1;
	if (lazya[rt])
	{
		tree[rt << 1] += lazya[rt] * (x[m + 1] - x[l]);
		lazya[rt << 1] += lazya[rt];
		tree[rt << 1 | 1] += lazya[rt] * (x[r + 1] - x[m + 1]);
		lazya[rt << 1 | 1] += lazya[rt];
		lazya[rt] = 0;
	}
	if (lazyk[rt])
	{
		tree[rt << 1] += 0.5 * lazyk[rt] * (x[m + 1] + x[l]) * (x[m + 1] - x[l]);
		lazyk[rt << 1] += lazyk[rt];
		tree[rt << 1 | 1] += 0.5 * lazyk[rt] * (x[r + 1] + x[m + 1]) * (x[r + 1] - x[m + 1]);
		lazyk[rt << 1 | 1] += lazyk[rt];
		lazyk[rt] = 0;
	}
}

double query(int L, int R, int rt = 1, int l = 1, int r = n)
{
	if (L <= l && r <= R)
	{
		return tree[rt];
	}
	pushdown(rt, l, r);
	int m = (l + r) >> 1;
	double ret = 0;
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

void update(int L, int R, double a, double k, int rt = 1, int l = 1, int r = n)
{
	if (L <= l && r <= R)
	{
		tree[rt] += a * (x[r + 1] - x[l]) + 0.5 * k * (x[r + 1] + x[l]) * (x[r + 1] - x[l]);
		lazya[rt] += a;
		lazyk[rt] += k;
		return;
	}
	pushdown(rt, l, r);
	int m = (l + r) >> 1;
	if (L <= m)
	{
		update(L, R, a, k, lchild);
	}
	if (R > m)
	{
		update(L, R, a, k, rchild);
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
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N;
		scanf("%d", &N);
		char s[2];
		n = 1;
		memset(tree, 0, sizeof tree);
		memset(lazya, 0, sizeof lazya);
		memset(lazyk, 0, sizeof lazyk);
		for (int i = 0; i < N; ++i)
		{
			scanf("%s", s);
			q[i].type = s[0];
			if (s[0] == 'Q')
			{
				scanf("%d %d", &q[i].l, &q[i].r);
				x[n++] = q[i].l;
				x[n++] = q[i].r;
			}
			else
			{
				scanf("%d", &q[i].l);
				for (int j = 0; j < q[i].l; ++j)
				{
					scanf("%d %d", &q[i].x[j], &q[i].y[j]);
					x[n++] = q[i].x[j];
					x[n++] = q[i].y[j];
				}
			}
		}
		sort(x + 1, x + 1 + n);
		n = unique(x + 1, x + 1 + n) - x - 1;
		id.clear();
		for (int i = 1; i <= n; ++i)
		{
			id[x[i]] = i;
		}
		build();
		for (int i = 0; i < N; ++i)
		{
			if (q[i].type == 'Q')
			{
				int l = id[q[i].l];
				int r = id[q[i].r];
				printf("%.3f\n", query(l, r - 1));
			}
			else
			{
				for (int j = 0; j < q[i].l; ++j)
				{
					q[i].x[j] = id[q[i].x[j]];
				}
				for (int j = 0; j < q[i].l; ++j)
				{
					if (q[i].x[j] < q[i].x[(j + 1) % q[i].l])
					{
						double k = (q[i].y[(j + 1) % q[i].l] - q[i].y[j]) * 1.0 / (x[q[i].x[(j + 1) % q[i].l]] - x[q[i].x[j]]);
						update(q[i].x[j], q[i].x[(j + 1) % q[i].l] - 1, -(q[i].y[j] - k * x[q[i].x[j]]), -k);
					}
					else
					{
						double k = (q[i].y[(j + 1) % q[i].l] - q[i].y[j]) * 1.0 / (x[q[i].x[(j + 1) % q[i].l]] - x[q[i].x[j]]);
						update(q[i].x[(j + 1) % q[i].l], q[i].x[j] - 1, (q[i].y[j] - k * x[q[i].x[j]]), k);
					}
				}
			}
		}
	}
	return 0;
}
