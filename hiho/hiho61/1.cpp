#include <cstdio>

char s[50001];
int N;
int tree1[50002];
int tree2[50002];
int tree41[50002];
int tree42[50002];
int pos;

inline int lowbit(int x)
{
	return x & (-x);
}

void update(int tree[], int x, int delta)
{
	while (x <= N)
	{
		tree[x] += delta;
		x += lowbit(x);
	}
}

int query(int tree[], int x)
{
	int ret = 0;
	while (x > 0)
	{
		ret += tree[x];
		x -= lowbit(x);
	}
	return ret;
}

int main()
{
	int M;
	scanf("%d %d", &N, &M);
	scanf("%s", s + 1);
	s[0] = 'A';
	for (int i = 1; i <= N; ++i)
	{
		update(tree2, i, s[i] - s[i - 1]);
	}
	N++;
	while (M--)
	{
		int cmd;
		scanf("%*s %d", &cmd);
		if (cmd == 1)
		{
			int l, r;
			char c;
			scanf("%d %d %c", &l, &r, &c);
			update(tree1, l, 1);
			update(tree1, r + 1, -1);
		}
		else if (cmd == 2)
		{
			int l, r, d;
			scanf("%d %d %d", &l, &r, &d);
		}
		else if (cmd == 3)
		{
			int K;
			scanf("%d", &K);
			pos += K;
		}
		else
		{
			int l, r;
			scanf("%d %d", &l, &r);
		}
	}
	return 0;
}
