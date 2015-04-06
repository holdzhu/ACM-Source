#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int m, n, s, t, i, j;
		scanf("%d %d %d %d %d %d", &m, &n, &s, &t, &i, &j);
		printf("%d %d\n", (i * n + j) / t, (i * n + j) % t);
	}
	return 0;
}
