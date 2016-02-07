#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, k, x;
int a[200010];
int cnt[31];

int main()
{
	scanf("%d %d %d", &n, &k, &x);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
		for (int j = 0; j < 31; ++j)
		{
			if (a[i] & (1ll << j))
			{
				cnt[j]++;
			}
		}
	}
	long long m = 1;
	for (int i = 0; i < k; ++i)
	{
		m *= x;
	}
	long long ans = 0;
	for (int i = 0; i < n; ++i)
	{
		long long t = 0;
		for (int j = 0; j < 31; ++j)
		{
			if (a[i] & (1ll << j))
			{
				if (cnt[j] > 1)
				{
					t |= (1ll << j);
				}
			}
			else
			{
				if (cnt[j] > 0)
				{
					t |= (1ll << j);
				}
			}
		}
		ans = max(ans, (m * a[i]) | t);
	}
	printf("%I64d\n", ans);
	return 0;
}
