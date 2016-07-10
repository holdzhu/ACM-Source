#include <cstdio>

void exgcd(long long x, long long y, long long &a, long long &b)
{
	if (!y)
	{
		a = 1;
		b = 0;
		return;
	}
	exgcd(y, x % y, b, a);
	b -= a * (x / y);
}

int main()
{
	long long a, b;
	scanf("%lld %lld", &a, &b);
	long long x, y;
	exgcd(a, b, x, y);
	printf("%lld\n", (x % b + b) % b);
	return 0;
}
