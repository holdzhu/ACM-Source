#include <cstdio>
#include <cstring>

#define lchild rt << 1, l, m
#define rchild rt << 1 | 1, m + 1, r

int n;
long long treemin[6000000];
long long treemax[6000000];
const long long INF = 100000000000;

inline long long min(long long a, long long b)
{
	return a < b ? a : b;
}

inline long long max(long long a, long long b)
{
	return a > b ? a : b;
}

void pushupmin(int rt)
{
	treemin[rt] = min(treemin[rt << 1], treemin[rt << 1 | 1]);
}

long long querymin(int L, int R, int rt = 1, int l = 1, int r = n)
{
	if (L <= l && r <= R)
	{
		return treemin[rt];
	}
	int m = (l + r) >> 1;
	long long ret = INF;
	if (L <= m)
	{
		ret = min(ret, querymin(L, R, lchild));
	}
	if (R > m)
	{
		ret = min(ret, querymin(L, R, rchild));
	}
	return ret;
}

void buildmin(int rt = 1, int l = 1, int r = n)
{
	if (l == r)
	{
		scanf("%lld", &treemin[rt]);
		return;
	}
	int m = (l + r) >> 1;
	buildmin(lchild);
	buildmin(rchild);
	pushupmin(rt);
}

void pushupmax(int rt)
{
	treemax[rt] = max(treemax[rt << 1], treemax[rt << 1 | 1]);
}

long long querymax(int L, int R, int rt = 1, int l = 1, int r = n)
{
	if (L <= l && r <= R)
	{
		return treemax[rt];
	}
	int m = (l + r) >> 1;
	long long ret = -INF;
	if (L <= m)
	{
		ret = max(ret, querymax(L, R, lchild));
	}
	if (R > m)
	{
		ret = max(ret, querymax(L, R, rchild));
	}
	return ret;
}

void buildmax(int rt = 1, int l = 1, int r = n)
{
	if (l == r)
	{
		treemax[rt] = treemin[rt];
		return;
	}
	int m = (l + r) >> 1;
	buildmax(lchild);
	buildmax(rchild);
	pushupmax(rt);
}

int main()
{
	int k;
	scanf("%d %d", &n, &k);
	memset(treemin, 0, sizeof treemin);
	memset(treemax, 0, sizeof treemax);
	buildmin();
	buildmax();
	for (int i = 0; i <= n - k; ++i)
	{
		if (i)
		{
			printf(" ");
		}
		printf("%lld", querymin(i + 1, i + k));
	}
	printf("\n");
	for (int i = 0; i <= n - k; ++i)
	{
		if (i)
		{
			printf(" ");
		}
		printf("%lld", querymax(i + 1, i + k));
	}
	printf("\n");
	return 0;
}
