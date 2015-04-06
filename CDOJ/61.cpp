#include <cstdio>

bool isprime(int num, int & call)
{
	call++;
	if (num < 2)
	{
		return false;
	}
	for (int i = 2; i * i <= num; ++i)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int n;
	scanf("%d", &n);
	int call = 0;
	int num = 0;
	while (n--)
	{
		int t;
		scanf("%d", &t);
		if (isprime(t, call))
		{
			num++;
		}
	}
	printf("%d %d\n", num, call);
	return 0;
}
