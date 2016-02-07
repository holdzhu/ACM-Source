#include <cstdio>
#include <algorithm>

int p[200000];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int t;
		scanf("%d", &t);
		t--;
		p[t] = i;
	}
	long long ans = 0;
	for (int i = 1; i < n; ++i)
	{
		ans += std::abs(p[i] - p[i - 1]);
	}
	printf("%I64d\n", ans);
	return 0;
}
