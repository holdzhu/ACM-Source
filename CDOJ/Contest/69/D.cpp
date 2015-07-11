#include <cstdio>

long long gcd(long long a, long long b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int main()
{
	long long c, d, w;
	scanf("%lld %lld %lld %*lld %*lld", &c, &d, &w);
	long long g = gcd(d * (d + w), (c + d) * (c + d + w));
	printf("%lld/%lld\n", d * (d + w) / g, (c + d) * (c + d + w) / g);
	return 0;
}
