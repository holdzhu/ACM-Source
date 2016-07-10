#include <cstdio>

int sum[300001];
int a[300000];

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
		sum[i + 1] = sum[i] + 1 - a[i];
	}
	int ansl = 0, ansr = 0;
	for (int i = 0; i <= n; ++i)
	{
		int l = i;
		int r = n;
		while (l < r)
		{
			int m = (l + r + 1) >> 1;
			if (sum[m] - sum[i] <= k)
				l = m;
			else
				r = m - 1;
		}
		if (ansr - ansl < l - i)
		{
			ansr = l;
			ansl = i;
		}
	}
	printf("%d\n", ansr - ansl);
	for (int i = ansl; i < ansr; ++i)
		a[i] = 1;
	for (int i = 0; i < n; ++i)
		printf("%d ", a[i]);
	return 0;
}
