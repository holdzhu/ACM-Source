#include <cstdio>

int main()
{
	int n, sum = 0;
	scanf("%d", &n);
	while (n--)
	{
		int t;
		scanf("%d", &t);
		sum += t;
	}
	printf("%d\n", sum);
	return 0;
}
