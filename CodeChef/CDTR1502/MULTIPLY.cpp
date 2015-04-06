#include <cstdio>
#include <cstring>

int main()
{
	int m, n;
	scanf("%d%d", &m, &n);
	int a[m], b[n];
	for (int i = 0; i < m; ++i)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &b[i]);
	}
	int s[m + n - 1];
	memset(s, 0, sizeof(s));
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			s[i + j] += a[i] * b[j];
		}
	}
	printf("%d", s[0]);
	for (int i = 1; i < m + n - 1; ++i)
	{
		printf(" + %dx^%d", s[i], i);
	}
	printf("\n");
	return 0;
}
