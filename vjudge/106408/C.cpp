#include <cstdio>

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n * n; ++i, puts(""))
		for (int j = 0; j < n * n; ++j)
			putchar((i % n * n + j % n + i / n + j / n * n) % (n * n) < k ? '*' : '.');
	return 0;
}
