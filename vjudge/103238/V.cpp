#include <cstdio>

const int mod = 100000007;

const int maxn = 1e7;
long long fac[maxn + 1];
long long inv[maxn + 1];
int p[maxn + 1];
bool isnotprime[maxn + 1];
long long pre[maxn + 1];
int cnt = 0;

int main()
{
	fac[0] = fac[1] = inv[1] = pre[1] = 1;
	for (int i = 2; i <= maxn; ++i)
	{
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = inv[mod % i] * (mod - mod / i) % mod;
		pre[i] = pre[i - 1];
		if (!isnotprime[i])
		{
			p[cnt++] = i;
			pre[i] = pre[i] * (mod + 1 - inv[i]) % mod;
		}
		for (int j = 0; j < cnt && i * p[j] <= maxn; ++j)
		{
			isnotprime[i * p[j]] = true;
			if (i % p[j] == 0)
				break;
		}
	}
	int N, M;
	while (scanf("%d %d", &N, &M) == 2 && N)
	{
		printf("%lld\n", (fac[N] * pre[M] % mod + mod - 1) % mod);
	}
	return 0;
}
