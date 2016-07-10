#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		int K, C, S;
		scanf("%d %d %d", &K, &C, &S);
		printf("Case #%d:", kase);
		if (C * S < K)
			puts(" IMPOSSIBLE");
		else
		{
			for (int i = 0; i * C < K; ++i)
			{
				long long id = 0;
				for (int j = i * C; j < (i + 1) * C && j < K; ++j)
				{
					id *= K;
					id += j;
				}
				printf(" %lld", id + 1);
			}
			puts("");
		}
	}
	return 0;
}
