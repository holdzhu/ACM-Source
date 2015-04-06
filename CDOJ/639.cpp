#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%.4f\n", (a + 1) * 1.0 / (a + b + 2));
	}
	return 0;
}
