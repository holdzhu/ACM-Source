#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int X, Y, K, N;
		scanf("%d %d %d %d", &X, &Y, &K, &N);
		bool flag = false;
		while (N--)
		{
			int p, c;
			scanf("%d %d", &p, &c);
			if (c <= K && X - Y <= p)
			{
				flag = true;
			}
		}
		if (flag)
		{
			printf("LuckyChef\n");
		}
		else
		{
			printf("UnluckyChef\n");
		}
	}
	return 0;
}
