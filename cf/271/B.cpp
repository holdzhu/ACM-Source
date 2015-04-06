#include <cstdio>

int main()
{
	int n, m;
	scanf("%d", &n);
	int a[n];
	int s = 0;
	for (int i = 0; i < n; ++i)
	{
		int t;
		scanf("%d", &t);
		s += t;
		a[i] = s;
	}
	scanf("%d", &m);
	int q;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d", &q);
		int j;
		for (j = 0; j < n; ++j)
		{
			if (q <= a[j])
			{
				break;
			}
		}
		printf("%d\n", j + 1);
	}
	return 0;
}
