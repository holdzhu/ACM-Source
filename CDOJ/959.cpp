#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);
	long long a[n];
	a[0] = 1;
	for (int i = 0; i < n - 1; ++i)
	{
		a[i + 1] = (a[i] + 1) * 3;
	}
	for (int i = 0; i < n; ++i)
	{
		printf("%lld ", a[n - 1 - i]);
	}
	printf("\n");
	return 0;
}
