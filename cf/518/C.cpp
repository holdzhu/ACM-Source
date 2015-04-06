#include <cstdio>

int main()
{
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	int a[n];
	int o[n + 1];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
		o[a[i]] = i;
	}
	long long s = 0;
	while (m--)
	{
		int t;
		scanf("%d", &t);
		s += o[t] / k + 1;
		if (o[t] > 0)
		{
			a[o[t]] = a[o[t] - 1];
			a[o[t] - 1] = t;
			o[a[o[t]]]++;
			o[t]--;
		}
	}
	printf("%I64d\n", s);
	return 0;
}
