#include <cstdio>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;

int x[6666];
int y[6666];
int z[6666];
long long dis[6666];

struct cmp
{
	bool operator () (const int& a, const int& b) const
	{
		return dis[a] > dis[b];
	}
};

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d %d", &x[i], &y[i], &z[i]);
		dis[i] = z[i] ? 0 : LLONG_MAX;
	}
	double ans = 0;
	for (int i = 0; i < n; ++i)
	{
		long long mindis = LLONG_MAX;
		int minone = -1;
		for (int j = 0; j < n; ++j)
		{
			if (z[j] != -1 && mindis > dis[j])
			{
				mindis = dis[j];
				minone = j;
			}
		}
		z[minone] = -1;
		ans += sqrt(dis[minone]);
		for (int j = 0; j < n; ++j)
		{
			if (z[j] != -1)
			{
				dis[j] = min(dis[j], 1LL * (x[minone] - x[j]) * (x[minone] - x[j]) + 1LL * (y[minone] - y[j]) * (y[minone] - y[j]));
			}
		}
	}
	printf("%.2f\n", ans);
	return 0;
}
