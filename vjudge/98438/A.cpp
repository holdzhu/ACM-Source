#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

int N, Q;
const int maxn = 1e5;
int a[maxn];
pair<int, pair<int, int> > q[maxn];
long long ans[maxn];
map<int, int> pre;

long long tree[maxn << 2];
long long lazy[maxn << 2];
long long mxtree[maxn << 2];
long long mxlazy[maxn << 2];

#define lchild rt << 1, l, m
#define rchild rt << 1 | 1, m + 1, r

void push_down(int rt)
{
	mxtree[rt << 1] = max(mxtree[rt << 1], tree[rt << 1] + mxlazy[rt]);
	mxlazy[rt << 1] = max(mxlazy[rt << 1], lazy[rt << 1] + mxlazy[rt]);
	mxtree[rt << 1 | 1] = max(mxtree[rt << 1 | 1], tree[rt << 1 | 1] + mxlazy[rt]);
	mxlazy[rt << 1 | 1] = max(mxlazy[rt << 1 | 1], lazy[rt << 1 | 1] + mxlazy[rt]);
	tree[rt << 1] += lazy[rt];
	lazy[rt << 1] += lazy[rt];
	tree[rt << 1 | 1] += lazy[rt];
	lazy[rt << 1 | 1] += lazy[rt];
	lazy[rt] = 0;
	mxlazy[rt] = 0;
}

void push_up(int rt)
{
	tree[rt] = max(tree[rt << 1], tree[rt << 1 | 1]);
	mxtree[rt] = max(mxtree[rt << 1], mxtree[rt << 1 | 1]);
}

void update(int L, int R, int delta, int rt = 1, int l = 0, int r = N - 1)
{
	if (L <= l && r <= R)
	{
		tree[rt] += delta;
		lazy[rt] += delta;
		mxtree[rt] = max(mxtree[rt], tree[rt]);
		mxlazy[rt] = max(mxlazy[rt], lazy[rt]);
		return;
	}
	if (lazy[rt] || mxlazy[rt]) push_down(rt);
	int m = (l + r) >> 1;
	if (L <= m) update(L, R, delta, lchild);
	if (R > m) update(L, R, delta, rchild);
	push_up(rt);
}

long long query(int L, int R, int rt = 1, int l = 0, int r = N - 1)
{
	if (L <= l && r <= R) return mxtree[rt];
	if (lazy[rt] || mxlazy[rt]) push_down(rt);
	int m = (l + r) >> 1;
	long long ret = 0;
	if (L <= m) ret = max(ret, query(L, R, lchild));
	if (R > m) ret = max(ret, query(L, R, rchild));
	return ret;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", a + i);
	}
	scanf("%d", &Q);
	for (int i = 0; i < Q; ++i)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		x--;
		y--;
		q[i].first = y;
		q[i].second.first = x;
		q[i].second.second = i;
	}
	sort(q, q + Q);
	for (int i = 0, j = 0; i < N; ++i)
	{
		update(pre[a[i]], i, a[i]);
		pre[a[i]] = i + 1;
		while (j < Q && q[j].first <= i)
		{
			ans[q[j].second.second] = query(q[j].second.first, i);
			j++;
		}
	}
	for (int i = 0; i < Q; ++i)
	{
		printf("%lld\n", ans[i]);
	}
	return 0;
}
