#include <cstdio>
#include <algorithm>

using namespace std;

struct Area
{
	int l, r;
	bool operator < (const Area &rhs) const 
	{
		return r < rhs.r || (r == rhs.r && l > rhs.l);
	}
};

int main()
{
	int n;
	scanf("%d", &n);
	Area a[n];
	for (int i = 0; i < n; ++i)
	{
		int x, w;
		scanf("%d %d", &x, &w);
		a[i].l = x - w;
		a[i].r = x + w;
	}
	sort(a, a + n);
	int t = -2000000000;
	int r = -2000000000;
	int c = 0;
	for (int i = 0; i < n; ++i)
	{
		if (a[i].l > t && a[i].l >= r)
		{
			c++;
			r = a[i].r;
		}
		t = max(t, a[i].l);
	}
	printf("%d\n", c);
	return 0;
}
