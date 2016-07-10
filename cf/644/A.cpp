#include <cstdio>

int main()
{
	int n, a, b;
	scanf("%d %d %d", &n, &a, &b);
	if (n <= a * b)
		for (int i = 0; i < a; ++i, puts(""))
			for (int j = 0; j < b; ++j)
			{
				int id = i * b + (~b & i & 1 ? b - 1 - j : j);
				printf("%d ", id < n ? id + 1 : 0);
			}
	else
		puts("-1");
	return 0;
}
