#include <cstdio>

int p[1000];

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	int m = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (i == a || i == b || i == c || i == d)
			continue;
		p[m++] = i;
	}
	if (n == 4)
		puts("-1");
	else if (n + 1 > k)
		puts("-1");
	else
	{
		printf("%d %d", a, c);
		for (int i = 0; i < m; ++i)
			printf(" %d", p[i]);
		printf(" %d %d\n", d, b);
		printf("%d %d", c, a);
		for (int i = 0; i < m; ++i)
			printf(" %d", p[i]);
		printf(" %d %d\n", b, d);
	}
	return 0;
}
