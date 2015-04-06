#include <cstdio>
#include <algorithm>

int main()
{
	int n, m;
	while (scanf("%d %d", &n, &m) == 2)
	{
		int a[n];
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &a[i]);
		}
		std::sort(a, a + n);
		for (int i = 0; i < m; ++i)
		{
			printf("%d ", a[n - i - 1]);
		}
		printf("\n");
	}
	return 0;
}
