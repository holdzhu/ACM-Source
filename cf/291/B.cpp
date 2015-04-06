#include <cstdio>

int main()
{
	int n, x0, y0;
	scanf("%d %d %d", &n, &x0, &y0);
	int x[n], y[n];
	int c = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d", &x[i], &y[i]);
		x[i] -= x0;
		y[i] -= y0;
		for (int j = 0; j <= i; ++j)
		{
			if (i == j)
			{
				c++;
			}
			else if (x[i] * y[j] == x[j] * y[i])
			{
				break;
			}
		}
	}
	printf("%d\n", c);
	return 0;
}
