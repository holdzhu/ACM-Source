#include <cstdio>
#include <cstring>
#include <algorithm>

#define INF 100000000

using namespace std;

struct Road
{
	int p, r;
	bool operator < (const Road rhs) const
	{
		return p < rhs.p;
	}
};

Road road[500000];
int d[500000];

int main()
{
	int n;
	int kase = 1;
	while (scanf("%d", &n) == 1)
	{
		for (int i = 0; i < n; ++i)
		{
			scanf("%d %d", &road[i].p, &road[i].r);
		}
		sort(road, road + n);
		for (int i = 0; i < n; ++i)
		{
			d[i] = INF;
		}
		for (int i = 0; i < n; ++i)
		{
			*lower_bound(d, d + n, road[i].r) = road[i].r;
		}
		int ans = n;
		for (int i = 0; i < n; ++i)
		{
			if (d[i] == INF)
			{
				ans = i;
				break;
			}
		}
		printf("Case %d:\nMy king, at most %d road%s can be built.\n\n", kase++, ans, ans == 1 ? "" : "s");
	}
	return 0;
}
