#include <cstdio>

int main()
{
	long long n, a, b, c;
	scanf("%I64d %I64d %I64d %I64d", &n, &a, &b, &c);
	if (b - c >= a || b > n)
	{
		printf("%I64d\n", n / a);
	}
	else
	{
		long long m = (n - c) / (b - c);
		long long rem = n - m * (b - c);
		printf("%I64d\n", m + rem / a);
	}
	return 0;
}
