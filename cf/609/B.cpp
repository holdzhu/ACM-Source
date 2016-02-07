#include <cstdio>

int cnt[11];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		int t;
		scanf("%d", &t);
		cnt[t]++;
	}
	int ans = 0;
	for (int i = 1; i < m; ++i)
	{
		for (int j = i + 1; j <= m; ++j)
		{
			ans += cnt[i] * cnt[j];
		}
	}
	printf("%d\n", ans);
	return 0;
}
