#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, F;
		scanf("%d %d", &n, &F);
		for (int i = 0; i < n - 1; ++i)
		{
			F -= (2 * (n - i) - 1) * (i + 1);
			if (F <= 0)
			{
				break;
			}
		}
		if (F > 0)
		{
			for (int i = 0; i < n - 1; ++i)
			{
				printf("%d ", i + 1);
			}
			printf("%d\n", F);
		}
		else
		{
			printf("-1\n");
		}
	}
	return 0;
}
