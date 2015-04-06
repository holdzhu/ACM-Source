#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, p;
		scanf("%d %d", &n, &p);
		int a[n + 1];
		a[0] = 0;
		for (int i = 1; i <= n; ++i)
		{
			int t;
			scanf("%d", &t);
			a[i] = (a[i - 1] + t) % p;
		}
		int maxl = 1;
		for (int i = 0; i <= n - maxl; ++i)
		{
			for (int j = n; j > i + 1; --j)
			{
				if (a[i] == a[j] && j - i > maxl)
				{
					maxl = j - i;
				}
			}
		}
		printf("%d\n", maxl);
	}
	return 0;
}
