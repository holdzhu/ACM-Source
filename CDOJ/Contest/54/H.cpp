#include <cstdio>
#include <cstring>

long long a[30];

int main()
{
	int n;
	scanf("%d", &n);
	memset(a, 0, sizeof(a));
	for (int i = 0; i < n; ++i)
	{
		int t;
		scanf("%d", &t);
		for (int j = 0; j < 30; ++j)
		{
			a[j] += t & 1; 
			t >>= 1;
		}
	}
	long long ans = 0;
	for (int i = 29; i >= 0; --i)
	{
		ans += a[i] * (a[i] - 1) / 2 + a[i] * (n - a[i]);
		ans <<= 1;
	}
	printf("%lld\n", ans);
	return 0;
}
