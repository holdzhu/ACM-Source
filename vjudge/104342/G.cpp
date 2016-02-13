#include <cstdio>
#include <set>

using namespace std;

const int maxn = 3e5;

int N, Q;
char s[maxn + 1];

int tree[maxn << 2];
int lazy[maxn << 2];
int sum[maxn + 1];

void push_down(int rt)
{
	tree[rt << 1] += lazy[rt];
	tree[rt << 1 | 1] += lazy[rt];
	lazy[rt << 1] += lazy[rt];
	lazy[rt << 1 | 1] += lazy[rt];
	lazy[rt] = 0;
}

void push_up(int rt)
{
	tree[rt] = min(tree[rt << 1], tree[rt << 1 | 1]);
}

void build(int rt = 1, int l = 0, int r = N - 1)
{
	if (l >= r)
	{
		tree[rt] = sum[l + 1];
		return;
	}
	int m = (l + r) >> 1;
	build(rt << 1, l, m);
	build(rt << 1 | 1, m + 1, r);
	push_up(rt);
}

void update(int L, int R, int val, int rt = 1, int l = 0, int r = N - 1)
{
	if (L <= l && r <= R)
	{
		tree[rt] += val;
		lazy[rt] += val;
		return;
	}
	if (lazy[rt])
		push_down(rt);
	int m = (l + r) >> 1;
	if (L <= m) update(L, R, val, rt << 1, l, m);
	if (R > m) update(L, R, val, rt << 1 | 1, m + 1, r);
	push_up(rt);
}

int main()
{
	scanf("%d %d", &N, &Q);
	scanf("%s", s);
	set<int> left, right;
	for (int i = 0; i < N; ++i)
	{
		if (s[i] == '(')
			left.insert(i), sum[i + 1] = sum[i] + 1;
		else
			right.insert(i), sum[i + 1] = sum[i] - 1;
	}
	build();
	while (Q--)
	{
		int q;
		scanf("%d", &q);
		q--;
		if (s[q] == '(')
		{
			s[q] = ')';
			right.insert(q);
			left.erase(q);
			update(q, N - 1, -2);
			int l = 0;
			int r = q;
			while (l < r)
			{
				int m = (l + r) >> 1;
				int p = *right.lower_bound(m);
				update(p, N - 1, 2);
				if (tree[1] >= 0)
					r = m;
				else
					l = m + 1;
				update(p, N - 1, -2);
			}
			l = *right.lower_bound(l);
			update(l, N - 1, 2);
			s[l] = '(';
			left.insert(l);
			right.erase(l);
			printf("%d\n", l + 1);
		}
		else
		{
			s[q] = '(';
			left.insert(q);
			right.erase(q);
			update(q, N - 1, 2);
			int l = 0;
			int r = q;
			while (l < r)
			{
				int m = (l + r) >> 1;
				int p = *left.lower_bound(m);
				update(p, N - 1, -2);
				if (tree[1] >= 0)
					r = m;
				else
					l = m + 1;
				update(p, N - 1, 2);
			}
			l = *left.lower_bound(l);
			update(l, N - 1, -2);
			s[l] = ')';
			right.insert(l);
			left.erase(l);
			printf("%d\n", l + 1);
		}
	}
	return 0;
}
