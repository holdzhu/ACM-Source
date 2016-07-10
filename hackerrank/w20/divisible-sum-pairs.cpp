#include <cstdio>

int cnt[100];

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		int a;
		scanf("%d", &a);
		a %= k;
		ans += cnt[(k - a) % k];
		++cnt[a];
	}
	printf("%d\n", ans);
	return 0;
}
