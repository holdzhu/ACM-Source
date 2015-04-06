#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		int a[n];
		int b[n];
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &b[i]);
		}
		long long d;
		scanf("%lld", &d);
		int minc = 0;
		long long mins = 100000000000000000LL;
		for (int i = 0; i < n; ++i)
		{
			long long ans = 0;
			if (a[i] > d)
			{
				ans = d;
			}
			else
			{
				ans = (d - b[i] - 1) / (a[i] - b[i]) * (a[i] + b[i]) + d - (d - b[i] - 1) / (a[i] - b[i]) * (a[i] - b[i]);
			}
			if (ans < mins)
			{
				mins = ans;
				minc = i + 1;
			}
		}
		printf("%d\n", minc);
	}
	return 0;
}
