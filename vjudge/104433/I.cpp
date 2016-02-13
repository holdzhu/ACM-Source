#include <cstdio>
#include <cstring>

const int mod = 1e9 + 7;

const int maxn = 1e5;

char s[1001];
char t[1001];

long long pow_mod(long long a, long long k)
{
	long long s = 1;
	while (k)
	{
		if (k & 1)
			s = s * a % mod;
		a = a * a % mod;
		k >>= 1;
	}
	return s;
}

int main()
{
	scanf("%s", s);
	scanf("%s", t);
	int n = strlen(s);
	int k;
	scanf("%d", &k);
	long long cnt = (pow_mod(n - 1, k) + (k & 1 ? 1 : -1)) * pow_mod(n, mod - 2) % mod;
	long long cnt0 = cnt - (k & 1 ? 1 : -1);
	long long ans = 0;
	for (int i = 0; i < n; ++i)
	{
		bool flag = true;
		for (int j = 0; j < n; ++j)
			if (s[j] != t[(j + i) % n])
				flag = false;
		if (flag)
			ans = (ans + (i == 0 ? cnt0 : cnt)) % mod;
	}
	printf("%I64d\n", (ans + mod) % mod);
	return 0;
}
