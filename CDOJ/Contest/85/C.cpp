#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);
	int ans = 0;
	for (int j = 1; ; ++ans, j *= 3)
	{
		if (n <= (j - 1) >> 1)
		{
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}
