#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1e5;
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
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		int a, b, k;
		scanf("%*d %d %*d %d %d", &a, &b, &k);
		if (a && b && k)
		{
			a /= k;
			b /= k;
			long long ans = 0;
			for (int i = 1; i <= a && i <= b; ++i)
				ans += 1ll * mu[i] * (a / i) * (b / i);
			long long rem = 0;
			int mi = min(a, b);
			for (int i = 1; i <= mi; ++i)
				rem += 1ll * mu[i] * (mi / i) * (mi / i);
			printf("Case %d: %I64d\n", kase, ans - rem / 2);
		}
		else
		{
			printf("Case %d: 0\n", kase);
		}
	}
	return 0;
}
