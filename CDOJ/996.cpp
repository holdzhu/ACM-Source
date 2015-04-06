#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		while (n--)
		{
			int t;
			scanf("%d", &t);
			if (t >= 90)
			{
				printf("A ");
			}
			else if (t >= 80)
			{
				printf("B ");
			}
			else if (t >= 70)
			{
				printf("C ");
			}
			else if (t >= 60)
			{
				printf("D ");
			}
			else
			{
				printf("E ");
			}
		}
		printf("\n");
	}
	return 0;
}
