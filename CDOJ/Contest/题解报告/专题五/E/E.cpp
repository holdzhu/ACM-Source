#include <cstdio>

bool gcd(long long a, long long b)
{
	if (a > b)
	{
		a ^= b ^= a ^= b;
	}
	if (a == 0)
	{
		return false;
	}
	if (!gcd(b % a, a))
	{
		return true;
	}
	long long t = b - b % a;
	return ((t - 1) / a + 1) % (a + 1) % 2 == 0;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		long long a, b;
		scanf("%lld %lld", &a, &b);
		if (gcd(a, b))
		{
			printf("zhizhitaidiaola\n");
		}
		else
		{
			printf("zhizhitaicanla\n");
		}
	}
	return 0;
}
