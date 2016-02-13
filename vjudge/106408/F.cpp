#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const double pi = acos(-1);
double x[100001], y[100001];
pair<double, pair<bool, int> > event[500001];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int k = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%lf %lf", &x[i], &y[i]);
		event[k++] = {atan2(y[i], x[i]), {1, 0}};
		while (event[i].first < event[0].first)
			event[i].first += pi * 2;
	}
	x[n] = x[0];
	y[n] = y[0];
	event[k++] = {event[0].first + pi * 2, {1, 0}};
	while (m--)
	{
		double x1, y1, x2, y2;
		scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
		if (x1 * y2 - x2 * y1 < 0)
		{
			swap(x1, x2);
			swap(y1, y2);
		}
		double t1 = atan2(y1, x1);
		double t2 = atan2(y2, x2);
		if (fabs(t1 - t2) < 1e-10)
			continue;
		while (t1 < event[0].first)
			t1 += pi * 2;
		while (t2 < t1)
			t2 += pi * 2;
		event[k++] = {t1 - 2 * pi, {0, 1}};
		event[k++] = {t2 - 2 * pi, {0, -1}};
		event[k++] = {t1, {0, 1}};
		event[k++] = {t2, {0, -1}};
	}
	sort(event, event + k);
	double ans = 0;
	double sum = 0;
	int c = 0;
	for (int i = 0, j = -1; i < k; ++i)
	{
		if (event[i].second.first)
		{
			j++;
			if (j)
				sum += hypot(x[j] - x[j - 1], y[j] - y[j - 1]);
			if (j == n)
			{
				if (c)
					ans += sum;
				break;
			}
		}
		else if (j >= 0)
		{
			double px = cos(event[i].first);
			double py = sin(event[i].first);
			double t = sum
					   + (py * x[j] - px * y[j])
							 / (py * (x[j] - x[j + 1]) - px * (y[j] - y[j + 1]))
							 * hypot(x[j] - x[j + 1], y[j] - y[j + 1]);
			if (!c)
				ans -= t;
			c += event[i].second.second;
			if (!c)
				ans += t;
		}
		else
			c += event[i].second.second;
	}
	printf("%.10f\n", ans);
	return 0;
}
