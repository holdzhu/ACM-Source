#include <cstdio>

bool isprime(int n)
{
	for (int i = 2; i * i <= n; ++i)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		if (isprime(n))
		{
			printf("%d\n", n - 1);
		}
		else if (n == 4)
		{
			printf("2\n");
		}
		else
		{
			printf("0\n");
		}
	}
	return 0;
}
