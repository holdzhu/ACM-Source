#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

const long long maxn = 3 * 1e18;
vector<long long> pows[64];
int vis[2000001];
long long n;
int r;

bool isprime(int x)
{
	for (int i = 2; i < x; ++i)
	{
		if (x % i == 0)
		{
			return false;
		}
	}
	return true;
}

void init()
{
	memset(vis, 0, sizeof vis);
	for (int i = 1; i <= 10000; ++i)
	{
		if (i * i <= 2000000)
		{
			vis[i * i] = 2;
		}
	}
	for (int i = 3; i <= 62; ++i)
	{
		if (isprime(i))
		{
			for (int j = 1; ; ++j)
			{
				if (vis[j] != i && vis[j])
				{
					continue;
				}
				bool flag = true;
				long long t = 1;
				for (int k = 0; k < i; ++k)
				{
					if (maxn / j < t)
					{
						flag = false;
						break;
					}
					t *= j;
				}
				if (flag)
				{
					pows[i].push_back(t);
					if (t <= 2000000)
					{
						vis[t] = i;
					}
				}
				else
				{
					break;
				}
			}
		}
	}
}

bool check(long long x)
{
	long long cnt = sqrt(x + 0.5);
	for (int i = 3; i <= r; ++i)
	{
		if (pows[i].size())
		{
			cnt += lower_bound(pows[i].begin(), pows[i].end(), x) - pows[i].begin();
		}
	}
	return x - cnt >= n;
}

bool check2(long long x)
{
	long long cnt = sqrt(x + 0.5);
	if (cnt * cnt == x)
	{
		return false;
	}
	for (int i = 3; i <= r; ++i)
	{
		if (pows[i].size())
		{
			int p = lower_bound(pows[i].begin(), pows[i].end(), x) - pows[i].begin();
			if (pows[i][p] == x)
			{
				return false;
			}
			cnt += p;
		}
	}
	return x - cnt == n;
}

int main()
{
	init();
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lld %d", &n, &r);
		long long l = n;
		long long r = n * 2 > maxn ? maxn : n * 2;
		while (l < r)
		{
			long long m = (l + r) >> 1;
			if (check(m))
			{
				r = m;
			}
			else
			{
				l = m + 1;
			}
		}
		for (; !check2(l); ++l);
		printf("%lld\n", l);
	}
	return 0;
}
