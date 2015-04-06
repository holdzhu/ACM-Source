#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		n += 2;
		int t = n / 3;
		if (n % 3 == 2)
		{
			printf("%d %d\n", t - 1, t * 2 - 1);
		}
		else
		{
			printf("%d %d\n", t - 1, t * 2 - 2);
		}
	}
	return 0;
}
