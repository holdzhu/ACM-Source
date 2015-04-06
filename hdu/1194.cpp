#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int s, d;
		scanf("%d %d", &s, &d);
		if (s < d || (s + d) % 2 == 1)
		{
			printf("impossible\n");
		}
		else
		{
			printf("%d %d\n", (s + d) / 2, (s - d) / 2);
		}
	}
	return 0;
}
