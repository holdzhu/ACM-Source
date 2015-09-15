#include <cstdio>
#include <cmath>

const double pi = acos(-1);

const double eps = 1e-15;
int dcmp(double x)
{
	if (fabs(x) < eps)
	{
		return 0;
	}
	return x < 0 ? -1 : 1;
}

struct Point
{
	double x, y;
	Point(double x = 0, double y = 0) : x(x), y(y) {}
};

typedef Point Vector;

Vector operator - (const Point& A, const Point& B)
{
	return Vector(A.x - B.x, A.y - B.y);
}

double Dot(const Vector& A, const Vector& B)
{
	return A.x * B.x + A.y * B.y;
}

double Cross(const Vector& A, const Vector& B)
{
	return A.x * B.y - A.y * B.x;
}

bool SegmentProperIntersection(Point a1, Point a2, Point b1, Point b2)
{
	double c1 = Cross(a2 - a1, b1 - a1), c2 = Cross(a2 - a1, b2 - a1),
		   c3 = Cross(b2 - b1, a1 - b1), c4 = Cross(b2 - b1, a2 - b1);
	return dcmp(c1) * dcmp(c2) < 0 && dcmp(c3) * dcmp(c4) < 0;
}

bool OnSegment(Point p, Point a1, Point a2)
{
	return dcmp(Cross(a1 - p, a2 - p)) == 0 && dcmp(Dot(a1 - p, a2 - p)) < 0;
}

const double INF = 1e23;
int n, m;
Point p[101];
double dis[101][101];
double d[101];
bool vis[101];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%lf %lf", &p[i].x, &p[i].y);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; ++i)
	{
		scanf("%lf %lf", &p[i + n].x, &p[i + n].y);
	}
	int mx = 0;
	for (int i = 1; i < n; ++i)
	{
		if (p[i].x > p[mx].x)
		{
			mx = i;
		}
	}
	Point p1 = p[mx];
	p1.x -= 1e-6;
	Point p2 = Point(5001, p[mx].y);
	p[n + m] = p[mx];
	p[n + m].y += 1e-8;
	p[mx].y -= 1e-8;
	for (int i = 0; i < n + m; ++i)
	{
		if (dcmp(p[i].y - p1.y) == 0)
		{
			p[i].y += 1e-8;
		}
	}
	for (int i = 0; i <= n + m; ++i)
	{
		for (int j = i + 1; j <= n + m; ++j)
		{
			bool flag = true;
			if (i < n)
			{
				double l = atan2((p[(i + n - 1) % n] - p[i]).y, (p[(i + n - 1) % n] - p[i]).x);
				double r = atan2((p[(i + 1) % n] - p[i]).y, (p[(i + 1) % n] - p[i]).x);
				if (dcmp(r - l) < 0)
				{
					r += pi * 2;
				}
				double m = atan2((p[j] - p[i]).y, (p[j] - p[i]).x);
				if (dcmp(m - l) < 0)
				{
					m += pi * 2;
				}
				if (dcmp(m - r) > 0)
				{
					flag = false;
				}
			}
			if (SegmentProperIntersection(p[i], p[j], p1, p2))
			{
				flag = false;
			}
			for (int k = 0; k < n && flag; ++k)
			{
				if (SegmentProperIntersection(p[i], p[j], p[k], p[(k + 1) % n]))
				{
					flag = false;
				}
			}
			for (int k = 0; k < m && flag; ++k)
			{
				if (SegmentProperIntersection(p[i], p[j], p[k + n], p[(k + 1) % m + n]))
				{
					flag = false;
				}
			}
			for (int k = 0; k < n + m && flag; ++k)
			{
				if (OnSegment(p[k], p[i], p[j]))
				{
					flag = false;
				}
			}
			dis[i][j] = dis[j][i] = flag ? hypot(p[i].x - p[j].x, p[i].y - p[j].y) : INF;
		}
	}
	for (int i = 0; i <= n + m; ++i)
	{
		d[i] = dis[mx][i];
	}
	vis[mx] = true;
	for (int i = 0; i < n + m; ++i)
	{
		int id = -1;
		for (int j = 0; j <= n + m; ++j)
		{
			if (!vis[j] && (id == -1 || d[j] < d[id]))
			{
				id = j;
			}
		}
		vis[id] = true;
		for (int j = 0; j <= n + m; ++j)
		{
			if (d[j] > d[id] + dis[id][j])
			{
				d[j] = d[id] + dis[id][j];
			}
		}
	}
	printf("%.10f\n", d[n + m]);
	return 0;
}
