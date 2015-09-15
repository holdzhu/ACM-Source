#include <cstdio>

long long check(int a, int b, int c, int l)
{
	if (a + b + l <= c)
	{
		return 1ll * (l + 1) * (l + 2) / 2;
	}
	l = c - a - b;
	if (l < 0)
	{
		return 0;
	}
	return 1ll * (l + 1) * (l + 2) / 2;
}

int main()
{
	int a, b, c, l;
	scanf("%d %d %d %d", &a, &b, &c, &l);
	long long ans = 0;
	for (int i = 0; i <= l; ++i)
	{
		ans += 1ll * (i + 1) * (i + 2) / 2;
	}
	for (int i = 0; i <= l; ++i)
	{
		ans -= check(a, b, c + i, l - i);
		ans -= check(a, c, b + i, l - i);
		ans -= check(b, c, a + i, l - i);
	}
	printf("%I64d\n", ans);
	return 0;
}
