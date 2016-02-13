#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1e6;
bool isnotprime[maxn + 1];
long long primes[maxn + 1];
int cnt;

long long solve(long long i, int j)
{
	return i == 0 || j < 0 ? i : solve(i, j - 1) - solve(i / primes[j], upper_bound(primes, primes + j, i / primes[j]) - primes - 1);
}

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
	for (int i = 0; i < cnt; ++i)
		primes[i] *= primes[i];
	int T;
	scanf("%d", &T);
	while (T--)
	{
		long long n;
		scanf("%lld", &n);
		printf("%lld\n", solve(n, upper_bound(primes, primes + cnt, n) - primes - 1));
	}
	return 0;
}
