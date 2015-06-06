#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>

using namespace std;

int k[2000];
int cnt[10000000];
long long ans[10000000];
int tmp[10000000];
int nestest[10000000];
int total;

long long gcd(long long a, long long b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int main()
{
	int n, s, t;
	scanf("%d %d %d", &n, &s, &t);
	total = 0;
	memset(cnt, 0, sizeof cnt);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &k[i]);
		cnt[k[i]]++;
		total++;
	}
	memset(ans, -1, sizeof ans);
	int last = -1;
	for (int i = s * 2 - 1; i >= 0; --i)
	{
		nestest[i % s] = last;
		if (cnt[i % s])
		{
			last = i % s;
		}
	}
	long long minans = LLONG_MAX;
	long long maxans = 0;
	long long sumans = 0;
	printf("asd\n");
	for (int i = 0; i < s; ++i)
	{
		if (cnt[i])
		{
			memcpy(tmp, cnt, sizeof tmp);
			ans[i] = 0;
			int tmptotal = total;
			int pos = i;
			while (1)
			{
				tmptotal--;
				tmp[pos]--;
				ans[i] += t;
				if (tmptotal == 0)
				{
					break;
				}
				pos = (pos + t) % s;
				while (tmp[pos] == 0)
				{
					ans[i] += (nestest[pos] + s - pos) % s;
					pos = nestest[pos];
				}
			}
			minans = min(ans[i], minans);
			maxans = max(ans[i], maxans);
			sumans += ans[i];
		}
	}
	for (int i = 0; i < s; ++i)
	{
		if (!cnt[i])
		{
			ans[i] = ans[nestest[i]] + (nestest[i] + s - i) % s;
			minans = min(ans[i], minans);
			maxans = max(ans[i], maxans);
			sumans += ans[i];
		}
	}
	long long K = gcd(sumans, s);
	printf("%lld\n%lld\n%lld/%lld\n", minans, maxans, sumans / K, s / K);
	return 0;
}
