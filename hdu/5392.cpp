#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

const unsigned int mod = 3221225473;
const int N = 3000000;
bool isprime[N + 1];
int fac[N + 1];
int p[N];
int cnt[N + 1];

unsigned long long pow_mod(unsigned long long a, unsigned long long k)
{
	unsigned long long s = 1;
	while (k)
	{
		if (k & 1)
		{
			s = s * a % mod;
		}
		a = a * a % mod;
		k >>= 1;
	}
	return s;
}

int main()
{
	memset(isprime, true, sizeof isprime);
	isprime[1] = false;
	for (int i = 1; i <= N; ++i)
	{
		if (isprime[i] && i < 10000)
		{
			for (int j = i * i; j <= N; j += i)
			{
				isprime[j] = false;
			}
		}
	}
	memset(fac, -1, sizeof fac);
	for (int i = 1; i <= N; ++i)
	{
		if (isprime[i])
		{
			for (int j = 1; i * j <= N; ++j)
			{
				if (fac[i * j] == -1)
				{
					fac[i * j] = i;
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
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &p[i]);
			p[i]--;
		}
		memset(cnt, 0, sizeof cnt);
		for (int i = 0; i < n; ++i)
		{
			if (p[i] != -1)
			{
				int c = 0;
				int z = i;
				while (p[z] != -1)
				{
					int t = p[z];
					p[z] = -1;
					z = t;
					c++;
				}
				map<int, int> tp;
				while (c > 1)
				{
					tp[fac[c]]++;
					c /= fac[c];
				}
				for (map<int, int>::iterator it = tp.begin(); it != tp.end(); ++it)
				{
					cnt[it->first] = max(cnt[it->first], it->second);
				}
			}
		}
		unsigned long long ans = 1;
		for (int i = 1; i <= N; ++i)
		{
			if (cnt[i])
			{
				ans = ans * pow_mod(i, cnt[i]) % mod;
			}
		}
		printf("%I64u\n", ans);
	}
	return 0;
}
