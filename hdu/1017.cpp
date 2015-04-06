#include <cstdio>

int main()
{
	int n, m, N;
	scanf("%d", &N);
	while (N--)
	{
		int kase = 1;
		while (scanf("%d %d", &n, &m) == 2 && n)
		{
			printf("Case %d: ", kase++);
			int c = 0;
			for (int i = 1; i < n - 1; ++i)
			{
				for (int j = i + 1; j < n; ++j)
				{
					int t = i * i + j * j + m;
					if (t / i / j * i * j == t)
					{
						c++;
					}
				}
			}
			printf("%d\n", c);
		}
		if (N)
		{
			printf("\n");
		}
	}
	return 0;
}
