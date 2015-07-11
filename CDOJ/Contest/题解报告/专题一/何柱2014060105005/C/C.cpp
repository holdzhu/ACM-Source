#include <cstdio>
#include <cstring>

int tree[2000000][2];
int sz = 1;

void add(int x)
{
	bool num[20];
	for (int i = 19; i >= 0; --i)
	{
		num[i] = x & 1;
		x >>= 1;
	}
	int u = 0;
	for (int i = 0; i < 20; ++i)
	{
		if (!tree[u][num[i]])
		{
			tree[u][num[i]] = sz++;
		}
		u = tree[u][num[i]];
	}
}

int check(int x)
{
	bool num[20];
	for (int i = 19; i >= 0; --i)
	{
		num[i] = !(x & 1);
		x >>= 1;
	}
	int u = 0;
	int rnt = 0;
	for (int i = 0; i < 20; ++i)
	{
		if (tree[u][num[i]])
		{
			u = tree[u][num[i]];
			rnt <<= 1;
			rnt += num[i];
		}
		else
		{
			u = tree[u][!num[i]];
			rnt <<= 1;
			rnt += !num[i];
		}
	}
	return rnt;
}

int main()
{
	memset(tree, 0, sizeof tree);
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int t;
		scanf("%d", &t);
		add(t);
	}
	int m;
	scanf("%d", &m);
	while (m--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		if (a == 1)
		{
			printf("%d\n", check(b));
		}
		else
		{
			add(b);
		}
	}
	return 0;
}
