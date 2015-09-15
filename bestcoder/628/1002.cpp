#include <cstdio>
#include <cmath>

int a[101];

const double eps = 1e-10;
int dcmp(double x)
{
	if (fabs(x) < eps)
	{
		return 0;
	}
	return -1;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &a[i]);
		}
		if (a[0] == 0)
		{
			bool flag = true;
			for (int i = 0; i < n; ++i)
			{
				if (a[i] != 0)
				{
					flag = false;
					break;
				}
			}
			puts(flag ? "Yes" : "No");
		}
		else if (n == 1)
		{
			puts("Yes");
		}
		else
		{
			double d = 1.0 * a[1] / a[0];
			bool flag = true;
			for (int i = 1; i < n; ++i)
			{
				if (a[i] == 0)
				{
					flag = false;
					break;
				}
				if (dcmp(d - 1.0 * a[i] / a[i - 1]) != 0)
				{
					flag = false;
					break;
				}
			}
			puts(flag ? "Yes" : "No");
		}
	}
	return 0;
}
