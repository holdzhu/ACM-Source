#include <cstdio>

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	int ans = 0;
	int t = k;
	for (int i = 0; i < k; ++i)
	{
		int m;
		scanf("%d", &m);
		int last;
		scanf("%d", &last);
		int first = -1;
		int tt = last;
		for (int j = 1; j < m; ++j)
		{
			int t;
			scanf("%d", &t);
			if (t != last + 1 && first == -1)
			{
				first = j;
			}
			last = t;
		}
		if (tt == 1)
		{
			if (first != -1)
			{
				t += m - first;
				ans += m - first;
			}
		}
		else
		{
			t += m - 1;
			ans += m - 1;
		}
	}
	ans += t - 1;
	printf("%d\n", ans);
	return 0;
}
