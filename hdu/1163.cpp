#include <cstdio>

int pow9(int x, int n)
{
	if (n == 0)
	{
		return 1;
	}
	if (n == 1)
	{
		return x;
	}
	int s = pow9(x, n / 2);
	s *= s;
	s %= 9;
	if (n % 2 == 1)
	{
		s *= x;
	}
	s %= 9;
	return s;
}

int main()
{
	int n;
	while (scanf("%d", &n) == 1 && n)
	{
		printf("%d\n", (pow9(n % 9, n) + 8) % 9 + 1);
	}
	return 0;
}
