#include <cstdio>

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int main()
{
	int a, b;
	while (scanf("%d %d", &a, &b) == 2)
	{
		int t = gcd(a, b);
		printf("%d\n", a / t * b);
	}
	return 0;
}
