#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const double eps = 1e-10;

struct Point
{
	double x, y;
	Point(double x = 0, double y = 0) : x(x), y(y) {}
};

typedef Point Vector;

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

struct Line
{
	Point P;
	Vector v;
	double ang;
	Line() {}
	Line(Point P, Vector v) : P(P), v(v) { ang = atan2(v.y, v.x); }
	bool operator < (const Line& L) const
	{
		return ang < L.ang;
	}
};

double Cross(Vector A, Vector B)
{
	return A.x * B.y - A.y * B.x;
}

bool OnLeft(Line L, Point p)
{
	return Cross(L.v, p - L.P) > 0;
}

Point GetIntersection(Line a, Line b)
{
	Vector u = a.P - b.P;
	double t = Cross(b.v, u) / Cross(a.v, b.v);
	return a.P + a.v * t;
}

int HalfplaneIntersection(Line* L, int n, Point* poly)
{
	sort(L, L + n);
	int first, last;
	Point *p = new Point[n];
	Line *q = new Line[n];
	q[first = last = 0] = L[0];
	for (int i = 1; i < n; ++i)
	{
		while (first < last && !OnLeft(L[i], p[last - 1])) last--;
		while (first < last && !OnLeft(L[i], p[first])) first++;
		q[++last] = L[i];
		if (fabs(Cross(q[last].v, q[last - 1].v)) < eps)
		{
			last--;
			if (OnLeft(q[last], L[i].P)) q[last] = L[i];
		}
		if (first < last) p[last - 1] = GetIntersection(q[last - 1], q[last]);
	}
	while (first < last && !OnLeft(q[first], p[last - 1])) last--;
	if (last - first <= 1) return 0;
	p[last] = GetIntersection(q[last], q[first]);
	int m = 0;
	for (int i = first; i <= last; ++i) poly[m++] = p[i];
	return m;
}

Line L[20004];
Point poly[20004];

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		double x1, y1, x2, y2;
		scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
		L[i] = Line(Point(x1, y1), Vector(x2 - x1, y2 - y1));
	}
	L[N] = Line(Point(0, 0), Vector(1, 0));
	L[N + 1] = Line(Point(10000, 0), Vector(0, 1));
	L[N + 2] = Line(Point(10000, 10000), Vector(-1, 0));
	L[N + 3] = Line(Point(0, 10000), Vector(0, -1));
	int m = HalfplaneIntersection(L, N + 4, poly);
	double ans = 0;
	for (int i = 0; i < m; ++i)
	{
		ans += Cross(poly[i], poly[(i + 1) % m]);
	}
	printf("%.1f\n", ans / 2);
	return 0;
}
