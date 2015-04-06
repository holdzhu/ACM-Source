#include <cstdio>
#include <cstring>

int N;
int a[50001];

int lowbit(int x)
{
	return x & (-x);
}

void update(int x, int d)
{
	while (x <= N)
	{
		a[x] += d;
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

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		scanf("%d", &N);
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= N; ++i)
		{
			int t;
			scanf("%d", &t);
			update(i, t);
		}
		char s[100];
		char c[6];
		int u, v;
		printf("Case %d:\n", kase);
		getchar();
		while (gets(s) && sscanf(s, "%s %d %d", c, &u, &v) == 3)
		{
			if (c[0] == 'Q')
			{
				printf("%d\n", query(v) - query(u - 1));
			}
			else if (c[0] == 'A')
			{
				update(u, v);
			}
			else if (c[0] == 'S')
			{
				update(u, -v);
			}
		}
	}
	return 0;
}
