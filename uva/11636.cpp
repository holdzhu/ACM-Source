#include <cstdio>

int main()
{
	int n, kase = 1;
	while (scanf("%d", &n) == 1 && n >= 0)
	{
		int c = 0;
		n--;
		while (n)
		{
			c++;
			n >>= 1;
		}
		printf("Case %d: %d\n", kase++, c);
	}
	return 0;
}
