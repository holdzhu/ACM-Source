#include <cstdio>

int rmq[1000000][20];

inline int min(int a, int b)
{
	return a > b ? b : a;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &rmq[i][0]);
	}
	for (int i = 1; (1 << i) <= n; ++i)
	{
		for (int j = 0; j <= n - (1 << i); ++j)
		{
			rmq[j][i] = min(rmq[j][i - 1], rmq[j + (1 << (i - 1))][i - 1]);
		}
	}
	scanf("%d", &n);
	while (n--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		a--;
		b--;
		int m;
		for (m = 1; 1 << m <= b - a; ++m);
		printf("%d\n", min(rmq[a][m - 1], rmq[b + 1 - (1 << (m - 1))][m - 1]));
	}
	return 0;
}
