#include <cstdio>
#include <cstring>

int a[100001];
bool b[100001];
int n;

int lowbit(int x)
{
	return x & (-x);
}

void update(int x, int v)
{
	while (x <= n)
	{
		a[x] += v;
		x += lowbit(x);
	}
}

int query(int x)
{
	int rnt = 0;
	while (x > 0)
	{
		rnt += a[x];
		x -= lowbit(x);
	}
	return rnt;
}

int lowerbound(int l, int r, int v)
{
	while (r - l > 0)
	{
		int m = (l + r) >> 1;
		int q = query(m);
		if (q < v)
		{
			l = m + 1;
		}
		else
		{
			r = m;
		}
	}
	return l;
}

int upperbound(int l, int r, int v)
{
	while (r - l > 0)
	{
		int m = (l + r) >> 1;
		int q = query(m);
		if (q == v)
		{
			l = m + 1;
		}
		else
		{
			r = m;
		}
	}
	return l;
}

int main()
{
	int m;
	scanf("%d %d", &n, &m);
	memset(a, 0, sizeof a);
	memset(b, 0, sizeof b);
	while (m--)
	{
		int t, v;
		scanf("%d %d", &t, &v);
		if (t == 0 && !b[v])
		{
			b[v] = true;
			update(v, 1);
		}
		else if (t == 1 && b[v])
		{
			b[v] = false;
			update(v, -1);
		}
		else if (t == 2)
		{
			if (b[v])
			{
				printf("0\n");
			}
			else
			{
				int val = query(v);
				printf("%d\n", upperbound(v, n + 1, val) - lowerbound(0, v, val) - 1);
			}
		}
	}
	return 0;
}
