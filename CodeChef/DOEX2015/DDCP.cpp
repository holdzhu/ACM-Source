#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		int cnt = 0;
		for (int i = 0; i <= a; ++i)
		{
			for (int j = 0; j <= b; ++j)
			{
				for (int k = 0; k <= c; ++k)
				{
					if (((i ^ j) | k) <= d)
					{
						cnt++;
					}
					printf("%d %d %d %d\n", i, j, k, ((i ^ j) | k));
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
