#include <cstdio>

long long pw5[20];
long long pw10[20];

int main()
{
	pw5[0] = pw10[0] = 1;
	for (int i = 1; i < 20; ++i)
	{
		pw5[i] = pw5[i - 1] * 5;
		pw10[i] = pw10[i - 1] * 10;
	}
	int T;
	scanf("%d", &T);
	while (T--)
	{
		long long K;
		scanf("%lld", &K);
		long long sum = 0;
		long long ans = 0;
		for (int i = 18; i >= 0; --i)
			for (int j = 0; j < 10; j += 2)
			{
				if (sum + pw5[i] >= K)
					break;
				ans += pw10[i] * 2;
				sum += pw5[i];
			}
		printf("%lld\n", ans);
	}
	return 0;
}
