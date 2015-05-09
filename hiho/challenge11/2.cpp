#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int a[100000];
bool vis[100001];
bool isprime[100001];
vector<int> primes;

int main()
{
	int n;
	scanf("%d", &n);
	memset(vis, 0, sizeof vis);
	memset(isprime, -1, sizeof isprime);
	for (int i = 2; i <= 1000; ++i)
	{
		if (isprime[i])
		{
			for (int j = i * i; j <= 100000; j += i)
			{
				isprime[j] = false;
			}
		}
	}
	for (int i = 2; i <= 100000; ++i)
	{
		if (isprime[i])
		{
			primes.push_back(i);
		}
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
		vis[a[i]] = true;
	}
	sort(a, a + n);
	n = unique(a, a + n) - a;
	for (int i = 0; i < n; ++i)
	{
		if (vis[a[i]])
		{
			bool flag = true;
			for (int j = a[i] * 2; j < 100001; j += a[i])
			{
				if (vis[j])
				{
					flag = false;
					break;
				}
			}
			vis[a[i]] = flag;
		}
	}
	vector<int> b;
	for (int i = 0; i < n; ++i)
	{
		if (vis[a[i]])
		{
			b.push_back(a[i]);
		}
	}
	long long ans = 0;
	int count = 0;
	for (int i = b.size() - 1; i >= 0 && count < 1000000; --i)
	{
		for (int j = b.size() - 1; j >= i && count < 1000000; --j)
		{
			count++;
			long long s = (long long)b[i] * b[j];
			long long p = 1;
			for (int k = 0; k < primes.size() && s != 1; ++k)
			{
				int c = 1;
				if (s < 100000 && isprime[s])
				{
					p *= 2;
					break;
				}
				while (s % primes[k] == 0)
				{
					c++;
					s /= primes[k];
				}
				p *= c;
			}
			ans = max(ans, p);
		}
	}
	printf("%lld\n", ans);
	return 0;
}
