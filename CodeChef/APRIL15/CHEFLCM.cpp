#include <cstdio>
#include <cmath>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N;
		scanf("%d", &N);
		long long ans = 0;
		int sqr = sqrt(N + 0.5);
		for (int i = 1; i <= sqr; ++i)
		{
			if (N % i == 0)
			{
				ans += i;
				ans += N / i;
			}
		}
		if (sqr * sqr == N)
		{
			ans -= sqr;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
