#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		int N;
		scanf("%d", &N);
		int last = 0;
		int lb = 0;
		int lbi = 0;
		int maxsum = -1001;
		int t;
		int s = 0;
		int e = 0;
		for (int i = 1; i <= N; ++i)
		{
			scanf("%d", &t);
			t += last;
			if (maxsum < t - lb)
			{
				maxsum = t - lb;
				s = lbi + 1;
				e = i;
			}
			if (t < lb)
			{
				lb = t;
				lbi = i;
			}
			last = t;
		}
		if (kase > 1)
		{
			printf("\n");
		}
		printf("Case %d:\n%d %d %d\n", kase, maxsum, s, e);
	}
	return 0;
}
