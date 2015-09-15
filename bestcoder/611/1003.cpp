#include <cstdio>
#include <cstring>

const int N = 10000000;
bool isprime[N + 1];
int mu[N + 1];
unsigned int a[N + 1];
unsigned int b[N + 1];
unsigned int c[N + 1];

int main()
{
	memset(isprime, true, sizeof isprime);
	for (int i = 2; i <= N; ++i)
	{
		if (isprime[i] && i < 10000)
		{
			for (int j = i * i; j <= N; j += i)
			{
				isprime[j] = false;
			}
		}
	}
	for (int i = 1; i <= N; ++i)
	{
		mu[i] = 1;
	}
	for (int i = 2; i <= N; ++i)
	{
		if (isprime[i])
		{
			mu[i] = -1;
			for (int j = i * 2; j <= N; j += i)
			{
				mu[j] *= -1;
			}
			if (i < 10000)
			{
				for (int j = i * i; j <= N; j += i * i)
				{
					mu[j] = 0;
				}
			}
		}
	}
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
		{
			a[i] = (n / i) * (n / i);
		}
		for (int i = 1; i <= n; ++i)
		{
			b[i] = 0;
			for (int j = 1; i * j <= n; ++j)
			{
				b[i] += mu[j] * a[i * j];
			}
		}
		for (int i = 1; i <= n; ++i)
		{
			printf("%u\n", b[i]);
			c[i] = 0;
			for (int j = 1; i * j <= n; ++j)
			{
				c[i] += b[i * j];
			}
			c[i] *= c[i];
		}
		unsigned int ans = 0;
		for (int i = 1; i <= n; ++i)
		{
			unsigned int tmp = 0;
			for (int j = 1; i * j <= n; ++j)
			{
				tmp += mu[j] * c[i * j];
			}
			ans += i * tmp;
		}
		printf("%u\n", ans);
	}
	return 0;
}
