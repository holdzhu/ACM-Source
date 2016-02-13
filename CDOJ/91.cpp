#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

const double pi = acos(-1);

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

const double eps = 1e-8;
int dcmp(double x)
{
	if (fabs(x) < eps)
	{
		return 0;
	}
	return x < 0 ? -1 : 1;
}

bool operator == (const Point& A, const Point& B)
{
	return dcmp(A.x - B.x) == 0 && dcmp(A.y - B.y) == 0;
}

double Dot(const Vector& A, const Vector& B)
{
	return A.x * B.x + A.y * B.y;
}

double Length(const Vector& A)
{
	return sqrt(Dot(A, A));
}

double Cross(const Vector& A, const Vector& B)
{
	return A.x * B.y - A.y * B.x;
}

struct Circle
{
	Point c;
	double r;
	Circle(Point c, double r) : c(c), r(r) {}
};

struct Line
{
	Point A, B;
	Line(Point A, Point B) : A(A), B(B) {}
};

double DistanceToLine(Point P, Line l)
{
	Vector v1 = l.B - l.A, v2 = P - l.A;
	return fabs(Cross(v1, v2)) / Length(v1);
}

vector<Circle> cirs;
vector<Line> lines;
vector<double> dis;
Point rp;

double check(double r)
{
	double ret = 0;
	for (int i = 0; i < cirs.size(); ++i)
	{
		if (dcmp(r + cirs[i].r - dis[i]) > 0)
		{
			if (dcmp(r - cirs[i].r - dis[i]) >= 0)
			{
				ret += 2 * pi * cirs[i].r;
			}
			else if (dcmp(r + dis[i] - cirs[i].r) > 0)
			{
				ret += 2 * acos((cirs[i].r * cirs[i].r + dis[i] * dis[i] - r * r) / (2 * dis[i] * cirs[i].r)) * cirs[i].r;
			}
		}
	}
	for (int i = 0; i < lines.size(); ++i)
	{
		if (dcmp(Length(lines[i].A - rp) - r) > 0)
		{
			double d = DistanceToLine(rp, lines[i]);
			if (dcmp(Length(lines[i].B - rp) - r) < 0)
			{
				if (Dot(lines[i].B - rp, lines[i].B - lines[i].A) > 0)
				{
					ret += sqrt(max(0.0, r * r - d * d)) + sqrt(max(0.0, Dot(lines[i].B - rp, lines[i].B - rp) - d * d));
				}
				else
				{
					ret += sqrt(max(0.0, r * r - d * d)) - sqrt(max(0.0, Dot(lines[i].B - rp, lines[i].B - rp) - d * d));
				}
			}
			else if (dcmp(r - d) > 0)
			{
				ret += 2 * sqrt(max(0.0, r * r - d * d));
			}
		}
		else if (dcmp(Length(lines[i].B - rp) - r) > 0)
		{
			double d = DistanceToLine(rp, lines[i]);
			if (Dot(lines[i].A - rp, lines[i].A - lines[i].B) > 0)
			{
				ret += sqrt(max(0.0, r * r - d * d)) + sqrt(max(0.0, Dot(lines[i].A - rp, lines[i].A - rp) - d * d));
			}
			else
			{
				ret += sqrt(max(0.0, r * r - d * d)) - sqrt(max(0.0, Dot(lines[i].A - rp, lines[i].A - rp) - d * d));
			}
		}
		else
		{
			ret += Length(lines[i].A - lines[i].B);
		}
	}
	return ret;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		int N;
		double M;
		scanf("%d %lf", &N, &M);
		cirs.clear();
		lines.clear();
		while (N--)
		{
			char s[2];
			scanf("%s", s);
			if (s[0] == 'C')
			{
				double x, y, r;
				scanf("%lf %lf %lf", &x, &y, &r);
				cirs.push_back(Circle(Point(x, y), r));
			}
			else
			{
				int n;
				Point last;
				scanf("%d %lf %lf", &n, &last.x, &last.y);
				Point first = last;
				for (int i = 0; i < n - 1; ++i)
				{
					double x, y;
					scanf("%lf %lf", &x, &y);
					lines.push_back(Line(last, Point(x, y)));
					last = Point(x, y);
				}
				lines.push_back(Line(last, first));
			}
		}
		scanf("%lf %lf", &rp.x, &rp.y);
		double len = 0;
		for (int i = 0; i < cirs.size(); ++i)
		{
			len += 2 * pi * cirs[i].r;
		}
		for (int i = 0; i < lines.size(); ++i)
		{
			len += Length(lines[i].A - lines[i].B);
		}
		printf("Case #%d: ", kase);
		if (dcmp(len - M) < 0)
		{
			puts("impossible");
		}
		else if (dcmp(len - M) == 0)
		{
			puts("inestimable");
		}
		else
		{
			dis.resize(cirs.size());
			for (int i = 0; i < cirs.size(); ++i)
			{
				dis[i] = Length(cirs[i].c - rp);
			}
			double l = 0;
			double r = 0;
			for (int i = 0; i < cirs.size(); ++i)
			{
				r = max(r, dis[i] + cirs[i].r);
			}
			for (int i = 0; i < lines.size(); ++i)
			{
				r = max(r, Length(lines[i].A - rp));
				r = max(r, Length(lines[i].B - rp));
			}
			while (r - l > 1e-10)
			{
				double m = (l + r) / 2;
				if (check(m) - M > 0)
				{
					r = m;
				}
				else
				{
					l = m;
				}
			}
			if (dcmp(check(l) - M) == 0)
			{
				printf("%.2f\n", l);
			}
			else
			{
				puts("impossible");
			}
		}
	}
	return 0;
}