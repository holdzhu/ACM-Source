#include <cstdio>

#define MAX 10000000000000000

long long high = 0;
long long low = 1;

int main()
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		low *= 2;
		high *= 2;
		if (low >= MAX)
		{
			low -= MAX;
			high++;
		}
	}
	if (high)
	{
		printf("%lld%16lld\n", high, low);
	}
	else
	{
		printf("%lld\n", low);
	}
	return 0;
}
