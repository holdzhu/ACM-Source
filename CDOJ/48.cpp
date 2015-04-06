#include <cstdio>

int main()
{
	int T;
	long long n, m;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lld %lld", &n, &m);
		printf("%lld\n", n * m - 1);
	}
	return 0;
}
