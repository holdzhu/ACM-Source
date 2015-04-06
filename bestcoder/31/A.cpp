#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, k;
		scanf("%d %d", &n, &k);
		int a[n];
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		long long sum = 0;
		for (int i = 0; i < n; ++i)
		{
			int l = lower_bound(a, a + n, a[i] - k) - a;
			int r = upper_bound(a, a + n, a[i] + k) - a;
			sum += r - l - 1;
		}
		printf("%lld\n", sum / 2);
	}
	return 0;
}
