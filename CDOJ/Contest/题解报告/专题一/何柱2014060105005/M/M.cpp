#include <cstdio>
#include <cstring>

int n;
long long a[100001];

int lowbit(int x)
{
	return x & (-x);
}

void update(int x, long long v)
{
	while (x <= n)
	{
		a[x] += v;
		x += lowbit(x);
	}
}

long long query(int x)
{
	long long rnt = 0;
	while (x > 0)
	{
		rnt += a[x];
		x -= lowbit(x);
	}
	return rnt;
}

int main()
{
	scanf("%d", &n);
	memset(a, 0, sizeof a);
	for (int i = 0; i < n; ++i)
	{
		int t;
		scanf("%d", &t);
		update(i + 1, t);
	}
	int m;
	scanf("%d", &m);
	while (m--)
	{
		int q, w, e;
		scanf("%d %d %d", &q, &w, &e);
		if (q == 1)
		{
			update(w, e - (query(w) - query(w - 1)));
		}
		else
		{
			printf("%lld\n", query(e) - query(w - 1));
		}
	}
	return 0;
}
