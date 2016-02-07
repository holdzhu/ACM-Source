#include <cstdio>

int main()
{
	long long n;
	scanf("%I64d", &n);
	n++;
	int l = 0;
	int r = 1e9;
	while (l < r)
	{
		int m = (l + r) / 2;
		long double s = (long double)m * (m + 1) * 3 + 1;
		if (s < 2e18)
		{
			long long t = 1ll * m * (m + 1) * 3 + 1;
			if (n > t)
			{
				l = m + 1;
			}
			else
			{
				r = m;
			}
		}
	}
	long long t = 1ll * l * (l - 1) * 3 + 1;
	if (n <= t + l)
	{
		long long s = n - t;
		long long x = 2ll * l - s;
		long long y = 2ll * s;
		printf("%I64d %I64d\n", x, y);
	}
	else if (n <= t + l + l)
	{
		long long s = n - t - l;
		long long x = l - 2ll * s;
		long long y = 2ll * l;
		printf("%I64d %I64d\n", x, y);
	}
	else if (n <= t + l + l + l)
	{
		long long s = n - t - l - l;
		long long x = -l - s;
		long long y = 2ll * l - s * 2ll;
		printf("%I64d %I64d\n", x, y);
	}
	else if (n <= t + l + l + l + l)
	{
		long long s = n - t - l - l - l;
		long long x = -2ll * l + s;
		long long y = -2ll * s;
		printf("%I64d %I64d\n", x, y);
	}
	else if (n <= t + l + l + l + l + l)
	{
		long long s = n - t - l - l - l - l;
		long long x = -l + s * 2ll;
		long long y = -2ll * l;
		printf("%I64d %I64d\n", x, y);
	}
	else
	{
		long long s = n - t - l - l - l - l - l;
		long long x = l + s;
		long long y = -2ll * l + 2ll * s;
		printf("%I64d %I64d\n", x, y);
	}
	return 0;
}
