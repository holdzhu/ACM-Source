#include <cstdio>
#include <cmath>
#include <cfloat>
#include <algorithm>

using namespace std;

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
	Point(double x = 0, double y = 0): x(x), y(y) {}
	bool operator < (const Point& rhs) const
	{
		return y < rhs.y || (y == rhs.y && x < rhs.x);
	}
	bool operator == (const Point& rhs) const
	{
		return x == rhs.x && y == rhs.y;
	}
};

Point operator - (Point A, Point B)
{
    return Point(A.x - B.x, A.y - B.y);
}

double Cross(Point A, Point B)
{
    return A.x * B.y - A.y * B.x;
}

int LeftConvexHull(Point* p, int n, Point* ch)
{
	sort(p, p + n);
	n = unique(p, p + n) - p;
	int m = 0;
	for (int i = n - 1; i >= 0; --i)
	{
		while (m > 1 && dcmp(Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2])) <= 0)
		{
			m--;
		}
		ch[m++] = p[i];
	}
	return m;
}

int RightConvexHull(Point* p, int n, Point* ch)
{
	sort(p, p + n);
	n = unique(p, p + n) - p;
	int m = 0;
	for (int i = 0; i < n; ++i)
	{
		while (m > 1 && dcmp(Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2])) <= 0)
		{
			m--;
		}
		ch[m++] = p[i];
	}
	return m;
}

inline double Dot(const Point& A, const Point& B)
{
	return A.x * B.x + A.y * B.y;
}

inline double Length(const Point& A)
{
	return sqrt(Dot(A, A));
}

inline double DistanceToSegment(const Point& P, const Point& A, const Point& B)
{
	if (A == B)
	{
		return Length(P - A);
	}
	Point v1 = B - A;
	Point v2 = P - A;
	Point v3 = P - B;
	if (dcmp(Dot(v1, v2)) < 0)
	{
		return Length(v2);
	}
	if (dcmp(Dot(v1, v3)) > 0)
	{
		return Length(v3);
	}
	return fabs(Cross(v1, v2)) / Length(v1);
}

int N, M, n, m;
Point demacia[10000];
Point noxus[10000];
Point demaciaCH[10000];
Point noxusCH[10000];

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i)
	{
		scanf("%lf %lf", &demacia[i].x, &demacia[i].y);
	}
	for (int i = 0; i < M; ++i)
	{
		scanf("%lf %lf", &noxus[i].x, &noxus[i].y);
	}
	n = RightConvexHull(demacia, N, demaciaCH);
	m = LeftConvexHull(noxus, M, noxusCH);
	int p = 0;
	double ans = DBL_MAX;
	for (int i = 0; i < n; ++i)
	{
		double d = Length(demaciaCH[i] - noxusCH[p]);
		double left = p > 0 ? DistanceToSegment(demaciaCH[i], noxusCH[p], noxusCH[p - 1]) : DBL_MAX;
		double right = p < m - 1 ? DistanceToSegment(demaciaCH[i], noxusCH[p], noxusCH[p + 1]) : DBL_MAX;
		if (left > right)
		{
			while (p < m - 1 && d >= DistanceToSegment(demaciaCH[i], noxusCH[p], noxusCH[p + 1]))
			{
				d = DistanceToSegment(demaciaCH[i], noxusCH[p], noxusCH[p + 1]);
				p++;
			}
		}
		else
		{
			while (p > 0 && d >= DistanceToSegment(demaciaCH[i], noxusCH[p], noxusCH[p - 1]))
			{
				d = DistanceToSegment(demaciaCH[i], noxusCH[p], noxusCH[p - 1]);
				p--;
			}
		}
		ans = min(ans, d);
	}
	p = 0;
	for (int i = 0; i < m; ++i)
	{
		double d = Length(noxusCH[i] - demaciaCH[p]);
		double left = p > 0 ? DistanceToSegment(noxusCH[i], demaciaCH[p], demaciaCH[p - 1]) : DBL_MAX;
		double right = p < n - 1 ? DistanceToSegment(noxusCH[i], demaciaCH[p], demaciaCH[p + 1]) : DBL_MAX;
		if (left > right)
		{
			while (p < n - 1 && d >= DistanceToSegment(noxusCH[i], demaciaCH[p], demaciaCH[p + 1]))
			{
				d = DistanceToSegment(noxusCH[i], demaciaCH[p], demaciaCH[p + 1]);
				p++;
			}
		}
		else
		{
			while (p > 0 && d >= DistanceToSegment(noxusCH[i], demaciaCH[p], demaciaCH[p - 1]))
			{
				d = DistanceToSegment(noxusCH[i], demaciaCH[p], demaciaCH[p - 1]);
				p--;
			}
		}
		ans = min(ans, d);
	}
	printf("%.5f\n", ans);
	return 0;
}
