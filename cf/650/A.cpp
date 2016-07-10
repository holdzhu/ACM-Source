#include <cstdio>
#include <algorithm>

using namespace std;

pair<int, int> p[200000];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d %d", &p[i].first, &p[i].second);
	sort(p, p + n);
	long long ans = 0;
	for (int i = 0; i < n;)
	{
		int j = i;
		for (; j < n && p[i] == p[j]; ++j)
			;
		ans -= 1ll * (j - i) * (j - i - 1) / 2;
		i = j;
	}
	for (int i = 0; i < n;)
	{
		int j = i;
		for (; j < n && p[i].first == p[j].first; ++j)
			;
		ans += 1ll * (j - i) * (j - i - 1) / 2;
		i = j;
	}
	for (int i = 0; i < n; ++i)
		swap(p[i].first, p[i].second);
	sort(p, p + n);
	for (int i = 0; i < n;)
	{
		int j = i;
		for (; j < n && p[i].first == p[j].first; ++j)
			;
		ans += 1ll * (j - i) * (j - i - 1) / 2;
		i = j;
	}
	printf("%I64d\n", ans);
	return 0;
}
