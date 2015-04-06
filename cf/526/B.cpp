#include <cstdio>

int n;
long long ans = 0;
int a[10000];

long long dfs(int rt, int de)
{
	if (de == n)
	{
		return a[rt];
	}
	long long l = dfs(rt << 1, de + 1);
	long long r = dfs(rt << 1 | 1, de + 1);
	if (l < r)
	{
		ans += r - l;
		return r + a[rt];
	}
	else
	{
		ans += l - r;
		return l + a[rt];
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 2; i < 1 << (n + 1); ++i)
	{
		scanf("%d", &a[i]);
	}
	dfs(1, 0);
	printf("%I64d\n", ans);
	return 0;
}
