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

inline int next(int x, int s)
{
	if (x == s - 1)
	{
		return 0;
	}
	return x + 1;
}

inline int previous(int x, int s)
{
	if (x == 0)
	{
		return s - 1;
	}
	return x - 1;
}

Point demacia[10000];
Point noxus[10000];
Point demaciaCH[10000];
Point noxusCH[10000];

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i)
	{
		scanf("%lf %lf", &demacia[i].x, &demacia[i].y);
	}
	for (int i = 0; i < M; ++i)
	{
		scanf("%lf %lf", &noxus[i].x, &noxus[i].y);
	}
	int n = RightConvexHull(demacia, N, demaciaCH);
	int m = LeftConvexHull(noxus, M, noxusCH);
	double ans = DBL_MAX;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			ans = min(ans, DistanceToSegment(demaciaCH[i], noxusCH[j], noxusCH[next(j, m)]));
		}
	}
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			ans = min(ans, DistanceToSegment(noxusCH[i], demaciaCH[j], demaciaCH[next(j, n)]));
		}
	}
	printf("%.5f\n", ans);
	return 0;
}
