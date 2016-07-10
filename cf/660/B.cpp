#include <cstdio>

int p[400];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int k = 0;
	for (int i = 1; i <= n; ++i)
	{
		p[k++] = 2 * n + i * 2 - 1;
		p[k++] = i * 2 - 1;
		p[k++] = 2 * n + i * 2;
		p[k++] = i * 2;
	}
	for (int i = 0; i < n * 4; ++i)
	{
		if (p[i] > m)
			continue;
		printf("%d ", p[i]);
	}
	return 0;
}
