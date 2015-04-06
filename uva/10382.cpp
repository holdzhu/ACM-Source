#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

pair<double, double> a[10000];

int main()
{
	int n, l, w;
	while (scanf("%d %d %d", &n, &l, &w) == 3)
	{
		int p, r;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d %d", &p, &r);
			double d = sqrt(r * r - w * w / 4.0);
			a[i] = make_pair(p - d, p + d);
		}
		sort(a, a + n);
		double rare = 0;
		int c = 1;
		double next = 0;
		bool b = false;
		for (int i = 0; i < n; ++i)
		{
			if (a[i].first > rare && a[i].second > next)
			{
				c++;
				if (a[i].first > next)
				{
					break;
				}
				rare = next;
			}
			next = max(next, a[i].second);
			if (next >= l)
			{
				b = true;
				break;
			}
		}
		printf("%d\n", b ? c : -1);
	}
	return 0;
}
