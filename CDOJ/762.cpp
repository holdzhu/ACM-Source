#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, k;
		scanf("%d %d", &n, &k);
		if (k > n - 1)
		{
			k = n - 1;
		}
		int s = n * k / 2;
		if (s < n - 1)
		{
			printf("0\n");
		}
		else
		{
			printf("%d\n", s);
		}
	}
	return 0;
}
