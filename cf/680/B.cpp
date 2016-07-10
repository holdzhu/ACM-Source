#include <cstdio>

int t[101];

int main()
{
	int n, a;
	scanf("%d %d", &n, &a);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &t[i]);
	int ans = t[a];
	for (int i = 1; a - i >= 1 || a + i <= n; ++i)
	{
		if (a - i < 1)
			ans += t[a + i];
		else if (a + i > n)
			ans += t[a - i];
		else if (t[a + i] + t[a - i] == 2)
			ans += 2;
	}
	printf("%d\n", ans);
	return 0;
}
