#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		int a = (n - 1) / 3;
		printf("%d\n", a * (a + 1) * 3 / 2 + (n - 1) % 3 * (a + 1));
	}
	return 0;
}
