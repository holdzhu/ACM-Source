#include <cstdio>
#include <cstring>
#include <cmath>

bool b[100001];

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int m, n;
		scanf("%d %d", &m, &n);
		int sqr = sqrt(n + 0.5);
		memset(b, true, sizeof b);
		if (m == 1)
		{
			b[0] = false;
		}
		for (int i = 2; i <= sqr; ++i)
		{
			for (int j = (m / i > 2 ? m / i : 2) * i; j <= n; j += i)
			{
				if (j >= m)
				{
					b[j - m] = false;
				}
			}
		}
		for (int i = 0; i <= n - m; ++i)
		{
			if (b[i])
			{
				printf("%d\n", i + m);
			}
		}
		if (t)
		{
			printf("\n");
		}
	}
	return 0;
}
