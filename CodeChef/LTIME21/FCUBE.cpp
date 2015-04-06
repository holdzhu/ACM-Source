#include <cstdio>
#include <cmath>

long long gcd(long long a, long long b)
{
	return b == 0 ? a : gcd(b, a % b);
}

inline long long min(long long a, long long b)
{
	return a > b ? b : a;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		long long ans = 1;
		long long a[n];
		for (int i = 0; i < n; ++i)
		{
			long long t;
			scanf("%lld", &t);
			for (long long j = min(1000000, (int)sqrt(t + 0.5)); j > 0; --j)
			{
				if (t % (j * j * j) == 0)
				{
					t /= (j * j * j);
					ans *= j;
					ans %= 1000000007;
					break;
				}
			}
			a[i] = t;
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (i != j)
				{
					long long t = gcd(a[i], a[j]);
					if (t > 1)
					{
						for (int k = 0; k < n; ++k)
						{
							if (i != k && j != k)
							{
								t = gcd(t, a[k]);
								ans *= t;
								ans %= 1000000007;
								a[i] /= t;
								a[j] /= t;
								a[k] /= t;
							}
						}
					}
				}
			}
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (i != j)
				{
					long long t = gcd(a[i], a[j]);
					ans *= t;
					ans %= 1000000007;
					a[i] /= t;
					a[j] /= t;
					if (a[i] % t == 0)
					{
						a[i] /= t;
					}
					else if (a[j] % t == 0)
					{
						a[j] /= t;
					}
				}
			}
		}
		for (int i = 0; i < n; ++i)
		{
			long long t = a[i];
			long long h = 1;
			for (int j = 2; j <= 1000000 && t > 1; ++j)
			{
				if (t % j == 0)
				{
					t /= j;
					if (t % j == 0)
					{
						h *= j;
						t /= j;
					}
					long long d = (long long)sqrt(t + 0.5);
					if (d * d == t)
					{
						h *= d;
						break;
					}
				}
			}
			a[i] /= h * h;
			ans *= h;
			ans %= 1000000007;
		}
		for (int i = 0; i < n; ++i)
		{
			ans *= a[i];
			ans %= 1000000007;
		}
		ans = ((ans % 1000000007) * (ans % 1000000007)) % 1000000007 * (ans % 1000000007);
		ans %= 1000000007;
		printf("%lld\n", ans);
	}
	return 0;
}
