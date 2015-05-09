#include <cstdio>
#include <algorithm>

using namespace std;

long long a[100000];

int main()
{
	int N;
	while (scanf("%d", &N) == 1)
	{
		for (int i = 0; i < N; ++i)
		{
			scanf("%lld", &a[i]);
		}
		sort(a, a + N);
		long long L = -3000000000;
		long long R = 3000000000;
		long long target = ((long long)N * (N - 1) / 2 - 1) / 2;
		while (R > L)
		{
			long long M = (L + R + 1) >> 1;
			long long sum = 0;
			for (int i = 0; i < N - 1; ++i)
			{
				sum += lower_bound(a + i + 1, a + N, M + a[i]) - (a + i + 1);
			}
			if (sum > target)
			{
				R = M - 1;
			}
			else
			{
				L = M;
			}
		}
		printf("%lld\n", L);
	}
	return 0;
}
