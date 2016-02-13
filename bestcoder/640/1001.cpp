#include <cstdio>

int x[20];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &x[i]);
		}
		int ans = n;
		for (int i = n - 1; i >= 0; --i)
		{
			if (x[i] == ans)
			{
				ans--;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
