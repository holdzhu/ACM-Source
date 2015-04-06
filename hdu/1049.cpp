#include <cstdio>

int main()
{
	int n, u, d;
	while (scanf("%d %d %d", &n, &u, &d) == 3 && n && u && d)
	{
		printf("%d\n", (n - d - 1) / (u - d) * 2 + 1);
	}
	return 0;
}
