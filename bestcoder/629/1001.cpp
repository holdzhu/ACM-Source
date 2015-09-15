#include <cstdio>
#include <cmath>

long long a[10000];
long long b[10000];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		long long sum = 0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%I64d", &a[i]);
		}
		for (int i = 0; i < n; ++i)
		{
			scanf("%I64d", &b[i]);
			sum += b[i] * b[i] * a[i];
		}
		int l = 0;
		int r = 1000;
		while (l < r)
		{
			int m = (l + r + 1) / 2;
			double tmp = 0; 
			for (int i = 0; i < n; ++i)
			{
				if (a[i] < m)
				{
					continue;
				}
				tmp += 1.0 * (a[i] - m) * b[i] * (a[i] - m) * (a[i] - m) * b[i] / a[i] / a[i];
			}
			if (tmp * 2 >= sum)
			{
				l = m;
			}
			else
			{
				r = m - 1;
			}
		}
		printf("%d\n", l);
	}
	return 0;
}
