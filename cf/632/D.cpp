#include <cstdio>
#include <algorithm>

using namespace std;

int a[1000000];
int cnt[1000001];
int f[1000001];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
		if (a[i] <= m)
			cnt[a[i]]++;
	}
	for (int i = 1; i <= m; ++i)
		for (int j = i; j <= m; j += i)
			f[j] += cnt[i];
	int ans = 1;
	for (int i = 1; i <= m; ++i)
		if (f[i] > f[ans])
			ans = i;
	printf("%d %d\n", ans, f[ans]);
	for (int i = 0; i < n; ++i)
		if (ans % a[i] == 0)
			printf("%d ", i + 1);
	return 0;
}
