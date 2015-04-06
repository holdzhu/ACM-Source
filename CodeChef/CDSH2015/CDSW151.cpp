#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int Z, N;
		scanf("%d %d", &N, &Z);
		long long a[N + 1];
		a[0] = 0;
		for (int i = 1; i <= N; ++i)
		{
			scanf("%lld", &a[i]);
			a[i] ^= a[i - 1];
		}
		int minc = -1;
		long long min = 10000000000000LL;
		for (int i = N - Z; i >= 0; --i)
		{
			if ((a[Z + i] ^ a[i]) < min)
			{
				min = a[Z + i] ^ a[i];
				minc = i + 1;
			}
		}
		printf("%d\n", minc);
	}
	return 0;
}
