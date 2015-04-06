#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, m, r;
		scanf("%d %d %d", &n, &m, &r);
		float b[m];
		int c[m];
		for (int i = 0; i < m; ++i)
		{
			b[i] = r * (i + 1) * 1.0 / m;
			c[i] = 0;
		}
		b[m - 1]++;
		while (n--)
		{
			int t;
			scanf("%d", &t);
			for (int i = 0; i < m; ++i)
			{
				if (t < b[i])
				{
					c[i]++;
					break;
				}
			}
		}
		for (int i = 0; i < m; ++i)
		{
			printf("%d ", c[i]);
		}
		printf("\n");
	}
	return 0;
}
