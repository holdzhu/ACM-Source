#include <cstdio>

int main()
{
	int na, nb, k, m;
	int a, b;
	scanf("%d %d %d %d", &na, &nb, &k, &m);
	for (int i = 0; i < na; ++i)
	{
		int t;
		scanf("%d", &t);
		if (i == k - 1)
		{
			a = t;
		}
	}
	for (int i = 0; i < nb; ++i)
	{
		int t;
		scanf("%d", &t);
		if (i == nb - m)
		{
			b = t;
		}
	}
	puts(a < b ? "YES" : "NO");
	return 0;
}
