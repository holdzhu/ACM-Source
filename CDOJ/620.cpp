#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

void gcd(long long a, long long b, long long& d, long long& x, long long& y)
{
	if (!b)
	{
		d = a;
		x = 1;
		y = 0;
	}
	else
	{
		gcd(b, a % b, d, y, x);
		y -= x * (a / b);
	}
}

inline long long ans(long long a, long long b)
{
	if (a >= 0 && b >= 0)
	{
		return max(a, b);
	}
	if (a <= 0 && b <= 0)
	{
		return max(-a, -b);
	}
	return abs(a) + abs(b);
}

inline long long solve(long long a, long long b, long long x, long long y, long long k)
{
	return ans(x + b * k, y - a * k);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		long long A, B, a, b;
		scanf("%lld %lld %lld %lld", &A, &B, &a, &b);
		long long d, x, y;
		gcd(a, b, d, x, y);
		if (abs((long long)A - B) % d == 0)
		{
			x *= abs((long long)A - B) / d;
			y *= abs((long long)A - B) / d;
			a /= d;
			b /= d;
			long long ans = solve(a, b, x, y, -x / b);
			ans = min(ans, solve(a, b, x, y, -x / b + 1));
			ans = min(ans, solve(a, b, x, y, -x / b - 1));
			ans = min(ans, solve(a, b, x, y, y / a));
			ans = min(ans, solve(a, b, x, y, y / a + 1));
			ans = min(ans, solve(a, b, x, y, y / a - 1));
			ans = min(ans, solve(a, b, x, y, (y - x) / (a + b)));
			ans = min(ans, solve(a, b, x, y, (y - x) / (a + b) + 1));
			ans = min(ans, solve(a, b, x, y, (y - x) / (a + b) - 1));
			if (a != b)
			{
				ans = min(ans, solve(a, b, x, y, (x + y) / (a - b)));
				ans = min(ans, solve(a, b, x, y, (x + y) / (a - b) + 1));
				ans = min(ans, solve(a, b, x, y, (x + y) / (a - b) - 1));
			}
			printf("%lld\n", ans);
		}
		else
		{
			printf("-1\n");
		}
	}
	return 0;
}
