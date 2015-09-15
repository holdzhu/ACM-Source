#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

int a[20];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		long long r;
		scanf("%d %I64d", &n, &r);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &a[i]);
		}
		sort(a, a + n, greater<int>());
		int ans = n + 1;
		for (int i = 0; i < (1 << n); ++i)
		{
			if (ans < __builtin_popcount(i))
			{
				continue;
			}
			long long t = r;
			for (int j = 0; j < n; ++j)
			{
				if (i & (1 << j))
				{
					t %= a[j];
				}
			}
			if (t == 0)
			{
				ans = __builtin_popcount(i);
			}
		}
		printf("%d\n", ans == n + 1 ? -1 : ans);
	}
	return 0;
}
