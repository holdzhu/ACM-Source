#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; ++t)
	{
		int N;
		scanf("%d", &N);
		while (--N)
		{
			int a, b;
			scanf("%d %d", &a, &b);
		}
		scanf("%d", &N);
		for (int i = 0; i < N - 1; ++i)
		{
			int a, b;
			scanf("%d %d", &a, &b);
		}
		printf("Case %d: ", t + 1);
		if (N <= 2)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}
	return 0;
}
