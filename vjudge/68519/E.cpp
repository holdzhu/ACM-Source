#include <cstdio>

int main()
{
	int N;
	while (scanf("%d", &N) == 1 && N)
	{
		long long a = 1;
		for (int i = 0; i < N; ++i)
		{
			a = a * (i * 4 + 2) / (i + 2);
		}
		printf("%lld\n", a);
	}
	return 0;
}
