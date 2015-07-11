#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

struct Point
{
	double x, y;
	int id;
	Point(double x = 0, double y = 0): x(x), y(y) {}
	bool operator < (const Point& rhs) const
	{
		return x < rhs.x || (x == rhs.x && y < rhs.y);
	}
};

Point p[5000];
Point tb[5000];

Point operator - (Point A, Point B)
{
    return Point(A.x - B.x, A.y - B.y);
}

double Cross(Point A, Point B)
{
    return A.x * B.y - A.y * B.x;
}

int ConvexHull(Point* p, int n, Point* ch)
{
	sort(p, p + n);
	int m = 0;
	for (int i = 0; i < n; ++i)
	{
		while (m > 1 && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) < 0)
		{
			m--;
		}
		ch[m++] = p[i];
	}
	int k = m;
	for (int i = n - 2; i >= 0; --i)
	{
		while (m > k && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) < 0)
		{
			m--;
		}
		ch[m++] = p[i];
	}
	if (n > 1)
	{
		m--;
	}
	return m;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 0; kase < T; ++kase)
	{
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N * 4; ++i)
		{
			scanf("%lf %lf", &p[i].x, &p[i].y);
		}
		int m = ConvexHull(p, N * 4, tb);
		double ans = 100000000000000000.0;
		for (int i = 0; i < m; ++i)
		{
			double dx = tb[i].x - tb[(i + 1) % m].x;
			double dy = tb[i].y - tb[(i + 1) % m].y;
			double up = 100000000000000000.0;
			double down = -100000000000000000.0;
			double left = 100000000000000000.0;
			double right = -100000000000000000.0;
			for (int j = 0; j < m; ++j)
			{
				up = min(up, (dy * tb[j].x - dx * tb[j].y) / sqrt(dx * dx + dy * dy));
				down = max(down, (dy * tb[j].x - dx * tb[j].y) / sqrt(dx * dx + dy * dy));
				left = min(left, (dx * tb[j].x + dy * tb[j].y) / sqrt(dx * dx + dy * dy));
				right = max(right, (dx * tb[j].x + dy * tb[j].y) / sqrt(dx * dx + dy * dy));
			}
			ans = min(ans, (down - up) * (right - left));
		}
		printf("Case #%d:\n", kase + 1);
		printf("%.0f\n", ans);
	}
	return 0;
}
