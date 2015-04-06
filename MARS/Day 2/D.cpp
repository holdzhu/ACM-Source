#include <cstdio>

struct Node
{
	long long val;
	long long mark;
};

Node tree[262141];

int num[100000];

void build(int root, int start, int end)
{
	tree[root].mark = 0;
	if (start == end)
	{
		tree[root].val = num[start];
	}
	else
	{
		int mid = (start + end) / 2;
		build(root * 2 + 1, start, mid);
		build(root * 2 + 2, mid + 1, end);
		tree[root].val = tree[root * 2 + 1].val + tree[root * 2 + 2].val;
	}
}

long long sum(int root, int nstart, int nend, int sstart, int send)
{
	if (sstart > nend || send < nstart)
	{
		return 0;
	}
	if (sstart <= nstart && nend <= send)
	{
		return tree[root].val;
	}
	int mid = (nstart + nend) / 2;
	if (tree[root].mark)
	{
		tree[root * 2 + 1].mark += tree[root].mark;
		tree[root * 2 + 2].mark += tree[root].mark;
		tree[root * 2 + 1].val += tree[root].mark * (mid - nstart + 1);
		tree[root * 2 + 2].val += tree[root].mark * (nend - mid);
		tree[root].mark = 0;
	}
	return sum(root * 2 + 1, nstart, mid, sstart, send) + sum(root * 2 + 2, mid + 1, nend, sstart, send);
}

void update(int root, int nstart, int nend, int ustart, int uend, int addval)
{
	if (ustart > nend || uend < nstart)
	{
		return;
	}
	if (ustart <= nstart && nend <= uend)
	{
		tree[root].mark += addval;
		tree[root].val += addval * (nend - nstart + 1);
		return;
	}
	int mid = (nstart + nend) / 2;
	if (tree[root].mark)
	{
		tree[root * 2 + 1].mark += tree[root].mark;
		tree[root * 2 + 2].mark += tree[root].mark;
		tree[root * 2 + 1].val += tree[root].mark * (mid - nstart + 1);
		tree[root * 2 + 2].val += tree[root].mark * (nend - mid);
		tree[root].mark = 0;
	}
	update(root * 2 + 1, nstart, mid, ustart, uend, addval);
	update(root * 2 + 2, mid + 1, nend, ustart, uend, addval);
	tree[root].val = tree[root * 2 + 1].val + tree[root * 2 + 2].val;
}
int main()
{
	int N, Q;
	scanf("%d %d", &N, &Q);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &num[i]);
	}
	build(0, 0, N - 1);
	while (Q--)
	{
		char s[2];
		scanf("%s", s);
		if (s[0] == 'Q')
		{
			int a, b;
			scanf("%d %d", &a, &b);
			printf("%lld\n", sum(0, 0, N - 1, a - 1, b - 1));
		}
		else
		{
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			update(0, 0, N - 1, a - 1, b - 1, c);
		}
	}
	return 0;
}
