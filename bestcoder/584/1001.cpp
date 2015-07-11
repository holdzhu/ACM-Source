#include <cstdio>

const int mod = 1000000007;
long long f[1000001];

int main()
{
	f[0] = f[1] = 1;
	for (int i = 2; i <= 1000000; ++i)
	{
		f[i] = (f[i - 1] + (i - 1) * f[i - 2] % mod) % mod;
	}
	int T;
	scanf("%d", &T);
	for (int kase = 0; kase < T; ++kase)
	{
		int N;
		scanf("%d", &N);
		printf("Case #%d:\n%I64d\n", kase + 1, f[N]);
	}
	return 0;
}
