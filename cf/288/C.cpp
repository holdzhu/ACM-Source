#include <cstdio>
#include <cstring>

int main()
{
	int m, t, r;
	scanf("%d %d %d", &m, &t, &r);
	int w[m];
	for (int i = 0; i < m; ++i)
	{
		scanf("%d", &w[i]);
	}
	if (t < r)
	{
		printf("-1\n");
	}
	else
	{
		int a[301];
		int c = 0;
		memset(a, 0, sizeof(a));
		for (int i = 0; i < m; ++i)
		{
			int T = r - a[w[i]];
			for (int j = 0; j < T; ++j)
			{
				for (int k = w[i] - j; k < w[i] + t - j && k <= 300; ++k)
				{
					if (k >= 0)
					{
						a[k]++;
					}
				}
			}
			c += T;
		}
		printf("%d\n", c);
	}
	return 0;
}
