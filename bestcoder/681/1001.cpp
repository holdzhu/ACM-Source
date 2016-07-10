#include <cstdio>
#include <cstring>

const int mod = 1e9 + 7;

char s[1001];
int cnt[26];
long long fac[1001];
long long inv[1001];
long long facinv[1001];

int main()
{
	fac[0] = fac[1] = inv[1] = facinv[0] = facinv[1] = 1;
	for (int i = 2; i <= 1000; ++i)
	{
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = inv[mod % i] * (mod - mod / i) % mod;
		facinv[i] = facinv[i - 1] * inv[i] % mod;
	}
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", s);
		int l = strlen(s);
		for (int i = 0; i < 26; ++i)
			cnt[i] = 0;
		for (int i = 0; i < l; ++i)
			cnt[s[i] - 'a']++;
		int oddcnt = 0;
		for (int i = 0; i < 26; ++i)
			if (cnt[i] & 1)
				oddcnt++;
		if (oddcnt > 1)
		{
			printf("0\n");
		}
		else
		{
			long long ans = 1;
			for (int i = 0; i < 26; ++i)
			{
				ans = ans * facinv[cnt[i] / 2] % mod;
			}
			ans = ans * fac[l / 2] % mod;
			printf("%I64d\n", ans);
		}
	}
	return 0;
}
