#include <cstdio>
#include <algorithm>

int main()
{
	int T;
	scanf("%d", &T);
	long long a[24];
	a[0] = 0;
	a[1] = 1;
	for (int i = 2; a[i - 1] < 1e16; ++i)
	{
		a[i] = a[i - 1] * 6 - a[i - 2] - 2;
	}
	while (T--)
	{
		long long G;
		scanf("%lld", &G);
		printf("%lld\n", *(std::upper_bound(a, a + 24, G)));
	}
	return 0;
}
