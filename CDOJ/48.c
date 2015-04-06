#include <cstdio>

int main()
{
	int T;
	long n, m;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%ld %ld", &n, &m);
		printf("%ld\n", n * m - 1);
	}
	return 0;
}
