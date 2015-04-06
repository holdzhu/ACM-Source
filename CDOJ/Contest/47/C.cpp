#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, m, L;
		scanf("%d %d %d", &n, &m, &L);
		long long s = 1;
		for (int i = 0; i < m; ++i)
		{
			int a, b;
			scanf("%d %d", &a, &b);
		}
		for (int i = n - 2; i > n - L; --i)
		{
			s *= i;
		}
		for (int i = 1; i < L - 1; ++i)
		{
			s /= i;
		}
		printf("%lld\n", s * m);
	}
	return 0;
}
