#include <cstdio>

int main()
{
	int a[50000];
	int m[50000];
	int c[50000];
	a[0] = 1;
	m[0] = 1;
	c[0] = 1;
	for (int i = 1; i < 50000; ++i)
	{
		if (i % 2)
		{
			a[i] = a[i / 2];
		}
		else
		{
			a[i] = a[i / 2 - 1] + a[i / 2];
		}
		if (a[i] > m[i - 1])
		{
			m[i] = a[i];
			c[i] = 1;
		}
		else if (a[i] == m[i - 1])
		{
			m[i] = m[i - 1];
			c[i] = c[i - 1] + 1;
		}
		else
		{
			m[i] = m[i - 1];
			c[i] = c[i - 1];
		}
	}
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		printf("%d %d %d ", a[n - 1], m[n - 1], c[n - 1]);
		int t = 0;
		for (int i = 0; i < c[n - 1]; )
		{
			if (a[t] == m[n - 1])
			{
				printf("%d ", t + 1);
				i++;
			}
			t++;
		}
		printf("\n");
	}
	return 0;
}
