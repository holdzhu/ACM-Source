#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N, K, C;
		scanf("%d %d %d", &N, &K, &C);
		int minx = N - 1;
		if (K % N == 0 || C <= K / N * N)
		{
			minx = 0;
		}
		else for (int i = N - 1; i > 0; --i)
		{
			if (C <= K / i * i || K / i > K % i / (N - i))
			{
				minx = N - i;
				break;
			}
		}
		printf("%d\n", C + minx);
	}
	return 0;
}
