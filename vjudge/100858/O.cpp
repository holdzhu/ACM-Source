#include <cstdio>
#include <cmath>
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

Vector operator / (Vector A, double p)
{
	return Vector(A.x / p, A.y / p);
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

bool SegmentProperIntersection(Point a1, Point a2, Point b1, Point b2)
{
	double c1 = Cross(a2 - a1, b1 - a1), c2 = Cross(a2 - a1, b2 - a1),
			c3 = Cross(b2 - b1, a1 - b1), c4 = Cross(b2 - b1, a2 - b1);
	return dcmp(c1) * dcmp(c2) < 0 && dcmp(c3) * dcmp(c4) < 0;
}

Point p[101];

int main()
{
	int xs, ys, xe, ye, re;
	while (scanf("%d %d %d %d %d", &xs, &ys, &xe, &ye, &re) == 5)
	{
		int N, T1, T2, T;
		scanf("%d %d %d %d", &N, &T1, &T2, &T);
		Point e = Point(xe, ye);
		Point s = Point(xs, ys);
		for (int i = 0; i < N; ++i)
		{
			scanf("%lf %lf", &p[i].x, &p[i].y);
		}
		p[N] = p[0];
		double area = 0;
		Point C;
		for (int i = 0; i < N; ++i)
		{
			double t = Cross(p[i], p[i + 1]);
			area += t;
			C.x += (p[i].x + p[i + 1].x) * t;
			C.y += (p[i].y + p[i + 1].y) * t;
		}
		C = C / (area * 3);
		Point newC = Rotate(C - e, pi * 2 * T / T1) + e;
		for (int i = 0; i < N; ++i)
		{
			p[i] = Rotate(p[i] - C, pi * 2 * T / T2) + newC;
		}
		double ang = acos(re / Length(s - e));
		double dis = Length(s - e);
		Point p1 = Rotate(s - e, ang) / dis * re + e;
		Point p2 = Rotate(s - e, -ang) / dis * re + e;
		double fur = Length(p1 - s);
		double deg1 = atan2(p1.y - s.y, p1.x - s.x);
		double deg2 = atan2(p2.y - s.y, p2.x - s.x);
		if (deg2 < deg1)
		{
			deg2 += pi * 2;
		}
		double mi = 1e9;
		double mx = -1e9;
		for (int i = 0; i < N; ++i)
		{
			if (dcmp(Length(p[i] - s) - fur) <= 0)
			{
				double deg = atan2(p[i].y - s.y, p[i].x - s.x);
				if (dcmp(deg1 - deg) > 0)
				{
					deg += 2 * pi;
				}
				if (dcmp(deg2 - deg) >= 0)
				{
					mi = min(mi, deg);
					mx = max(mx, deg);
				}
			}
			if (SegmentProperIntersection(s, p1, p[i], p[i + 1]))
			{
				mi = min(mi, deg1);
				mx = max(mx, deg1);
			}
			if (SegmentProperIntersection(s, p2, p[i], p[i + 1]))
			{
				mi = min(mi, deg2);
				mx = max(mx, deg2);
			}
		}
		if (mi > mx)
		{
			printf("%.2f\n", 2 * ang * re);
			continue;
		}
		double deg3 = atan2(e.y - s.y, e.x - s.x);
		if (deg3 < deg1)
		{
			deg3 += 2 * pi;
		}
		printf("%.2f\n", (ang * 2 - (asin(dis * sin(mx - deg3) / re) - mx) + (asin(dis * sin(mi - deg3) / re) - mi)) * re);
	}
	return 0;
}
