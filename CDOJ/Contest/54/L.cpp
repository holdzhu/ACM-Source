#include <cstdio>
#include <algorithm>

using namespace std;

struct A
{
	int v, w;
	bool operator < (const A& a) const
	{
		int s1 = max(0, a.v - w) + v;
		int s2 = max(0, v - a.w) + a.v;
		return s1 < s2;
	}
};

int main()
{
	int n;
	scanf("%d", &n);
	A a[n];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d", &a[i].v, &a[i].w);
	}
	sort(a, a + n);
	long long cur = 0;
	long long ans = 0;
	for (int i = 0; i < n; ++i)
	{
		if (cur < a[i].v)
		{
			ans += a[i].v - cur;
			cur = a[i].v;
		}
		cur -= a[i].v;
		cur += a[i].w;
	}
	printf("%lld\n", ans);
	return 0;
}
