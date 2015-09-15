#include <cstdio>
#include <cmath>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

const double pi = acos(-1);

const double eps = 1e-10;
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

struct Line
{
	Point a;
	Vector b;
	Line(Point a, Vector b) : a(a), b(b) {}
};

struct Circle
{
	Point o;
	double r;
};

Vector operator + (Vector A, Vector B)
{
	return Vector(A.x + B.x, A.y + B.y);
}

Vector operator - (Point A, Point B)
{
	return Vector(A.x - B.x, A.y - B.y);
}

Vector operator * (Vector A, double p)
{
	return Vector(A.x * p, A.y * p);
}

double Dot(Vector A, Vector B)
{
	return A.x * B.x + A.y * B.y;
}

double Length(Vector A)
{
	return sqrt(Dot(A, A));
}

double Cross(Vector A, Vector B)
{
	return A.x * B.y - A.y * B.x;
}

Vector Rotate(Vector A, double rad)
{
	return Vector(A.x * cos(rad) - A.y * sin(rad), A.x * sin(rad) + A.y * cos(rad));
}

vector<Line> lines;
Circle circle[10];

int n, x, y;

bool check(Point p)
{
	vector<pair<double, double> > degree;
	for (int i = 0; i < n; ++i)
	{
		if (dcmp(circle[i].r - Length(circle[i].o - p)) > 0)
		{
			return false;
		}
		double d = atan2(circle[i].o.y - p.y, circle[i].o.x - p.x);
		double a = asin(circle[i].r / Length(circle[i].o - p));
		degree.push_back(make_pair(d - a, d + a));
		degree.push_back(make_pair(d - a + pi * 2, d + a + pi * 2));
		degree.push_back(make_pair(d - a - pi * 2, d + a - pi * 2));
	}
	sort(degree.begin(), degree.end());
	for (int i = 1; i < degree.size(); ++i)
	{
		if (dcmp(degree[i].first - degree[i - 1].second) < 0)
		{
			return false;
		}
	}
	return true;
}

Point solve()
{
	for (int i = 0; i < lines.size(); ++i)
	{
		for (int j = i; j < lines.size(); ++j)
		{
			double d = Cross(lines[i].b, lines[j].b);
			if (dcmp(d) != 0)
			{
				double u = Cross(lines[j].b, lines[i].a - lines[j].a);
				double t = u / d;
				Point p = lines[i].a + lines[i].b * t;
				if (dcmp(p.x) >= 0 && dcmp(p.y) >= 0 && dcmp(p.x - x) <= 0 && dcmp(p.y - y) <= 0)
				{
					if (check(p))
					{
						return p;
					}
				}
			}
		}
	}
	return Point(-1, -1);
}

int main()
{
	freopen("zen.in", "r", stdin);
	freopen("zen.out", "w", stdout);
	scanf("%d %d %d", &n, &x, &y);
	for (int i = 0; i < n; ++i)
	{
		scanf("%lf %lf %lf", &circle[i].o.x, &circle[i].o.y, &circle[i].r);
	}
	lines.push_back(Line(Point(0, 0), Vector(0, 1)));
	lines.push_back(Line(Point(x, 0), Vector(0, 1)));
	lines.push_back(Line(Point(0, 0), Vector(1, 0)));
	lines.push_back(Line(Point(0, y), Vector(1, 0)));
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			double d = asin((circle[i].r + circle[j].r) / Length(circle[i].o - circle[j].o));
			Point p((circle[i].o.x * circle[j].r + circle[j].o.x * circle[i].r) / (circle[i].r + circle[j].r),
					(circle[i].o.y * circle[j].r + circle[j].o.y * circle[i].r) / (circle[i].r + circle[j].r));
			lines.push_back(Line(p, Rotate(circle[i].o - circle[j].o, d)));
			lines.push_back(Line(p, Rotate(circle[i].o - circle[j].o, -d)));
		}
	}
	Point p = solve();
	if (dcmp(p.x) < 0)
	{
		printf("No Zen\n");
	}
	else
	{
		printf("%.10f %.10f\n", p.x, p.y);
	}
	return 0;
}