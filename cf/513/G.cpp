#include <cstdio>

int a[100];
int c = 0;
int n, k;
double inversion = 0;

void dfs(int d)
{
	if (d < k)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = i; j < n; ++j)
			{
				for (int k = 0; k < (j - i + 1) / 2; ++k)
				{
					int t = a[i + k];
					a[i + k] = a[j - k];
					a[j - k] = t;
				}
				dfs(d + 1);
				for (int k = 0; k < (j - i + 1) / 2; ++k)
				{
					int t = a[i + k];
					a[i + k] = a[j - k];
					a[j - k] = t;
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < n - 1; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				if (a[i] > a[j])
				{
					inversion++;
				}
			}
		}
		c++;
	}
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
	}
	dfs(0);
	printf("%.15lf\n", inversion / c);
	return 0;
}
