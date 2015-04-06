#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		int c = 1;
		int maxl = 0;
		int t = 1;
		int a[n];
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &a[i]);
			if (i > 0)
			{
				if (a[i] == a[i - 1])
				{
					t++;
				}
				else
				{
					if (t > maxl)
					{
						maxl = t;
						c = 1;
					}
					else if (t == maxl)
					{
						c++;
					}
					t = 1;
				}
			}
		}
		if (t > maxl)
		{
			maxl = t;
			c = 1;
		}
		else if (t == maxl)
		{
			c++;
		}
		printf("%d %d\n{%d", c, maxl, a[0]);
		for (int i = 1; i < n; ++i)
		{
			if (a[i] == a[i - 1])
			{
				printf(",%d", a[i]);
			}
			else
			{
				printf("},{%d", a[i]);
			}
		}
		printf("}\n");
	}
	return 0;
}
