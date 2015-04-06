#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N;
		scanf("%d", &N);
		int a = 0;
		int c = 0;
		for (int i = 0; i < 15; ++i)
		{
			int t;
			scanf("%d", &t);
			if (t > a)
			{
				c++;
			}
			a = t;
		}
		printf("%d %d\n", N, c);
	}
	return 0;
}
