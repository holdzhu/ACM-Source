#include <cstdio>
#include <cstring>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		int c[200];
		memset(c, 0, sizeof(c));
		while (n--)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			a = (a - 1) / 2;
			b = (b - 1) / 2;
			if (a > b)
			{
				for (int i = b; i <= a; ++i)
				{
					c[i]++;
				}
			}
			else
			{
				for (int i = a; i <= b; ++i)
				{
					c[i]++;
				}
			}
		}
		int max = 0;
		for (int i = 0; i < 200; ++i)
		{
			if (c[i] > max)
			{
				max = c[i];
			}
		}
		printf("%d\n", max * 10);
	}
	return 0;
}
