#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point
{
	double x, y;
};

Point p[100000];
Point t[100000];
int n;

bool cmpx(const Point a, const Point b)
{
	return a.x < b.x;
}

bool cmpy(const Point a, const Point b)
{
	return a.y < b.y;
}

double solve(int l, int r)
{
	if (l == r)
	{
		return 1e10;
	}
	int m = (l + r) / 2;
	double s = min(solve(l, m), solve(m + 1, r));
	int c = 0;
	for (int i = m; i <= r && p[i].x < p[m].x + s; ++i)
	{
		t[c++] = p[i];
	}
	for (int i = m - 1; i >= l && p[i].x > p[m].x - s; --i)
	{
		t[c++] = p[i];
	}
	sort(t, t + c, cmpy);
	for (int i = 0; i < c; ++i)
	{
		for (int j = i + 1; j < c && j < i + 8 && t[j].y < t[i].y + s; ++j)
		{
			s = min(s, (t[i].x - t[j].x) * (t[i].x - t[j].x) + (t[i].y - t[j].y) * (t[i].y - t[j].y));
		}
	}
	return s;
}

int main()
{
	while (scanf("%d", &n) == 1 && n)
	{
		for (int i = 0; i < n; ++i)
		{
			scanf("%lf %lf", &p[i].x, &p[i].y);
		}
		sort(p, p + n, cmpx);
		printf("%.2f\n", sqrt(solve(0, n - 1)) / 2);
	}
	return 0;
}
