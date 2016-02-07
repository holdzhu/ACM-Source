#include <cstdio>
#include <algorithm>

using namespace std;

int a[101];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", a + i);
	}
	sort(a, a + n);
	int ans = 0;
	for (int i = n - 1; i >= 0 && m > 0; --i)
	{
		m -= a[i];
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}
