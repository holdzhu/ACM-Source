#include <cstdio>

int floyd[4000000];
int ans[4000000];

int main()
{
	int N, D;
	scanf("%d %d", &N, &D);
	if (N % D == 0)
	{
		printf("%d.0\n", N / D);
	}
	else
	{
		int a = N / D;
		N %= D;
		int p = 0;
		while (1)
		{
			floyd[p * 2] = N;
			N *= 10;
			ans[p * 2] = N / D;
			N %= D;
			floyd[p * 2 + 1] = N;
			N *= 10;
			ans[p * 2 + 1] = N / D;
			N %= D;
			if (floyd[p] == floyd[p * 2 + 1])
			{
				break;
			}
			p++;
		}
		int p2 = p * 2 + 1;
		while (p > 0 && floyd[p - 1] == floyd[p2 - 1])
		{
			p--;
			p2--;
		}
		printf("%d.", a);
		for (int i = 0; i < p; ++i)
		{
			printf("%d", ans[i]);
		}
		if (N)
		{
			putchar('(');
			for (int i = p; i < p2; ++i)
			{
				printf("%d", ans[i]);
			}
			putchar(')');
		}
		puts("");
	}
	return 0;
}
