#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; ++i)
	{
		long long N;
		scanf("%lld", &N);
		long long s = N * (N + 2);
		s %= 160880864;
		s *= (2 * N + 1) % 160880864;
		s %= 160880864;
		s /= 8;
		printf("Case #%d: %lld\n", i + 1, s);
	}
	return 0;
}
