#include <cstdio>

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int main()
{
	int STEP, MOD;
	while (scanf("%d %d", &STEP, &MOD) == 2)
	{
		printf("%10d%10d    %s\n\n", STEP, MOD, gcd(STEP, MOD) == 1 ? "Good Choice" : "Bad Choice");
	}
	return 0;
}
