#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

pair<pair<int, int>, int> circles[40000];

int main()
{
	freopen("ice.in", "r", stdin);
	freopen("ice.out", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	double mx = -1e18;
	for (int i = 0; i < m; ++i)
	{
		int x, y, r;
		scanf("%d %d %d", &x, &y, &r);
		circles[i] = {{x - r, x + r}, y};
	}
	sort(circles, circles + m);
	double last = -1e18;
	priority_queue<pair<int, int> > pq;
	double ans = 0;
	int cnt = 0;
	for (int i = 0, j = 0; i <= n; ++i)
	{
		while (j < m && circles[j].first.first <= i)
			pq.push({circles[j].second, j}), j++;
		while (pq.size() && circles[pq.top().second].first.second < i)
			pq.pop();
		double cur;
		if (pq.empty())
			cur = -1e18;
		else
		{
			auto &cir = circles[pq.top().second];
			double r  = 1.0 * (cir.first.second - cir.first.first) / 2;
			double x  = 1.0 * (cir.first.second + cir.first.first) / 2;
			cur		= cir.second + sqrt(r * r - (i - x) * (i - x));
		}
		double h = max(last, cur);
		if (i && h > -1e18)
		{
			mx = max(mx, h);
			ans += h;
			cnt++;
		}
		last = cur;
	}
	printf("%.15f\n", mx - ans / cnt);
	return 0;
}
