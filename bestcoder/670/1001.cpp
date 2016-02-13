#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		unsigned long long ans = 1ull * n * (n - 1) / 2 * (n - 2) / 3 * (n - 3) / 4 + n;
		printf("%I64d\n", ans);
	}
	return 0;
}
