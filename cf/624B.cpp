#include <cstdio>
#include <algorithm>

using namespace std;

int a[26];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	long long ans = 0;
	int mx = 2e9;
	for (int i = n - 1; i >= 0; --i)
	{
		a[i] = min(mx, a[i]);
		ans += a[i];
		mx = a[i] ? a[i] - 1 : 0;
	}
	printf("%I64d\n", ans);
	return 0;
}
