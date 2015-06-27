#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const double eps = 1e-9;
const double pi = acos(-1);

struct Point
{
	double x, y;
	bool operator < (const Point& rhs) const
	{
		return x < rhs.x || (x == rhs.x && y < rhs.y);
	}
};

struct Rect
{
	Point p[4];
};

typedef Point Vector;

int dcmp(double a)
{
	if (a <= -eps)
	{
		return -1;
	}
	return a >= eps;
}

Vector operator - (const Point& A, const Point& B)
{
	return (Vector){A.x - B.x, A.y - B.y};
}

double dot(const Vector& A, const Vector& B)
{
	return A.x * B.x + A.y * B.y;
}

double len(const Vector& A)
{
	return sqrt(dot(A, A));
}

double cross(const Vector& A, const Vector& B)
{
	return A.x * B.y - A.y * B.x;
}

Vector rotate(Vector A, double rad)
{
	return (Vector){A.x * cos(rad) - A.y * sin(rad), A.x * sin(rad) + A.y * cos(rad)};
}

int convex(Point* p, int n, Point* ch)
{
	sort(p, p + n);
	int m = 0;
	for (int i = 0; i < n; ++i)
	{
		while (m > 1 && dcmp(cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2])) <= 0)
		{
			m--;
		}
		ch[m++] = p[i];
	}
	int k = m;
	for (int i = n - 2; i >= 0; --i)
	{
		while (m > k && dcmp(cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2])) <= 0)
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

int next(int n, int mod)
{
	if (n == mod - 1)
	{
		return 0;
	}
	return n + 1;
}

Rect minRect(Point* ch, int n)
{
	double angle = 0;
	int left = 0;
	int right = 0;
	int top = 0;
	int bottom = 0;
	for (int i = 0; i < n; ++i)
	{
		if (ch[i].x < ch[left].x)
		{
			left = i;
		}
		if (ch[i].x > ch[right].x)
		{
			right = i;
		}
		if (ch[i].y > ch[top].y)
		{
			top = i;
		}
		if (ch[i].y < ch[bottom].y)
		{
			bottom = i;
		}
	}
	int tbottom = bottom;
	Rect rect;
	rect.p[0] = (Point){ch[left].x, ch[top].y};
	rect.p[1] = (Point){ch[left].x, ch[bottom].y};
	rect.p[2] = (Point){ch[right].x, ch[bottom].y};
	rect.p[3] = (Point){ch[right].x, ch[top].y};
	double minArea = (ch[top].y - ch[bottom].y) * (ch[right].x - ch[left].x);
	while (1)
	{
		while (dcmp(cross(ch[next(right, n)] - ch[right], rotate(ch[next(bottom, n)] - ch[bottom], pi / 2)) >= 0))
		{
			right = next(right, n);
		}
		while (dcmp(cross(ch[next(top, n)] - ch[top], rotate(ch[next(bottom, n)] - ch[bottom], pi)) >= 0))
		{
			top = next(top, n);
		}
		while (dcmp(cross(ch[next(left, n)] - ch[left], rotate(ch[next(bottom, n)] - ch[bottom], pi * 3 / 2)) >= 0))
		{
			left = next(left, n);
		}
		angle = atan2(ch[next(bottom, n)].y - ch[bottom].y, ch[next(bottom, n)].x - ch[bottom].x);
		bottom = next(bottom, n);
		Point tl = rotate(ch[left], -angle);
		Point tr = rotate(ch[right], -angle);
		Point tt = rotate(ch[top], -angle);
		Point tb = rotate(ch[bottom], -angle);
		double area = fabs((tt.y - tb.y) * (tr.x - tl.x));
		if (area < minArea)
		{
			minArea = area;
			rect.p[0] = rotate((Vector){tl.x, tt.y}, angle);
			rect.p[1] = rotate((Vector){tl.x, tb.y}, angle);
			rect.p[2] = rotate((Vector){tr.x, tb.y}, angle);
			rect.p[3] = rotate((Vector){tr.x, tt.y}, angle);
		}
		if (tbottom == bottom)
		{
			break;
		}
	}
	return rect;
}

Point p[80000];
Point c[80000];

int main()
{
	int N, M;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%lf %lf", &p[i].x, &p[i].y);
	}
	M = convex(p, N, c);
	Rect rect = minRect(c, M);
	for (int i = 0; i < 4; ++i)
	{
		printf("%.10f %.10f\n", rect.p[i].x, rect.p[i].y);
	}
	return 0;
}
