#include <cstdio>

inline int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		int a[n + 2];
		a[0] = 0;
		a[n + 1] = 101;
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d", &a[i]);
		}
		if (m >= n)
		{
			printf("100\n");
		}
		else
		{
			int ans = 0;
			for (int i = 0; i < n - m + 1; ++i)
			{
				ans = max(ans, a[i + m + 1] - a[i] - 1);
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
