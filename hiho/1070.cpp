#include <cstdio>

int tree[400001];
int n;

inline int min(int a, int b)
{
	return a < b ? a : b;
}

void build(int root, int L, int R)
{
	if (L == R)
	{
		scanf("%d", &tree[root]);
		return;
	}
	int M = (L + R) >> 1;
	build(root << 1, L, M);
	build(root << 1 | 1, M + 1, R);
	tree[root] = min(tree[root << 1], tree[root << 1 | 1]);
}

void update(int p, int delta, int root, int L, int R)
{
	if (L == R)
	{
		tree[root] = delta;
		return;
	}
	int M = (L + R) >> 1;
	if (p <= M)
	{
		update(p, delta, root << 1, L, M);
	}
	else
	{
		update(p, delta, root << 1 | 1, M + 1, R);
	}
	tree[root] = min(tree[root << 1], tree[root << 1 | 1]);
}

int query(int l, int r, int root, int L, int R)
{
	if (l <= L && R <= r)
	{
		return tree[root];
	}
	int M = (L + R) >> 1;
	int ret = 100000000;
	if (l <= M)
	{
		ret = min(ret, query(l, r, root << 1, L, M));
	}
	if (r > M)
	{
		ret = min(ret, query(l, r, root << 1 | 1, M + 1, R));
	}
	return ret;
}

int main()
{
	scanf("%d", &n);
	build(1, 0, n - 1);
	int m;
	scanf("%d", &m);
	while (m--)
	{
		int s, L, R;
		scanf("%d %d %d", &s, &L, &R);
		if (s)
		{
			update(L - 1, R, 1, 0, n - 1);
		}
		else
		{
			printf("%d\n", query(L - 1, R - 1, 1, 0, n - 1));
		}
	}
	return 0;
}
