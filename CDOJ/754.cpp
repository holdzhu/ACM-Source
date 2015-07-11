#include <cstdio>
#include <cmath>

inline long long trible(long long x)
{
	return x * x * x;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		long long d, n;
		scanf("%lld %lld", &d, &n);
		if (n % d == 0)
		{
			n /= d;
			long long t = n;
			long long sq = sqrt(n + 0.5);
			long long ans = 1;
			for (int i = 2; i <= sq && i <= n && t > 1; ++i)
			{ 
				long long c = 0;
				while (t % i == 0)
				{
					c++;
					t /= i;
				}
				if (c)
				{
					long long po = ((trible(c + 1) - 2 * trible(c)) + trible(c - 1));
					ans *= po;
				}
			}
			if (t > 1)
			{
				long long po = ((trible(2) - 2 * trible(1)) + trible(0));
				ans *= po;
			}
			printf("%lld\n", ans);
		}
		else
		{
			printf("0\n");
		}
	}
	return 0;
}