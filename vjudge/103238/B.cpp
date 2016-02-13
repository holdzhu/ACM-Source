#include <cstdio>

const int maxn = 5e6;
unsigned long long ans[maxn + 1];
unsigned long long pre[maxn + 1];
int mu[maxn + 1];
int primes[maxn + 1];
bool isnotprime[maxn + 1];
int cnt = 0;

int main()
{
	for (int i = 2; i <= maxn; ++i)
	{
		if (!isnotprime[i])
			primes[cnt++] = i;
		for (int j = 0; j < cnt && i * primes[j] <= maxn; ++j)
		{
			isnotprime[i * primes[j]] = true;
			if (i % primes[j] == 0)
				break;
		}
	}
	for (int i = 1; i <= maxn; ++i)
		mu[i] = 1;
	for (int i = 0; i < cnt; ++i)
	{
		for (int j = 1; j * primes[i] <= maxn; ++j)
			mu[j * primes[i]] *= -1;
		for (int j = 1; 1ll * j * primes[i] * primes[i] <= maxn; ++j)
			mu[j * primes[i] * primes[i]] = 0;
	}
	for (int i = 1; i <= maxn; ++i)
		for (int j = 1; i * j <= maxn; ++j)
			pre[i * j] += (unsigned long long)i * (i - 1) / 2;
	for (int i = 1; i <= maxn; ++i)
		for (int j = 1; i * j <= maxn; ++j)
			ans[i * j] += pre[i] * j * mu[j];
	for (int i = 1; i <= maxn; ++i)
		ans[i] *= i;
	for (int i = 1; i <= maxn; ++i)
		ans[i] += ans[i - 1];
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		int n;
		scanf("%d", &n);
		printf("Case %d: %llu\n", kase, ans[n]);
	}
	return 0;
}
