#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const double pi = acos(-1);

struct Point
{
	double x, y;
	Point(double x = 0, double y = 0) : x(x), y(y) {}
	bool operator < (const Point& rhs) const
	{
		return x < rhs.x || (x == rhs.x && y < rhs.y);
	}
};

typedef Point Vector;

Vector operator - (Vector A, Vector B)
{
	return Vector(A.x - B.x, A.y - B.y);
}

const double eps = 1e-10;
int dcmp(double x)
{
	if (fabs(x) < eps)
	{
		return 0;
	}
	else
	{
		return x < 0 ? -1 : 1;
	}
}

double Cross(Vector A, Vector B)
{
	return A.x * B.y - A.y * B.x;
}

Point ch[100000];
Point p;
double deg[100000];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		p.x = 0;
		p.y = 0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%lf %lf", &ch[i].x, &ch[i].y);
			p.x += ch[i].x;
			p.y += ch[i].y;
		}
		p.x /= n;
		p.y /= n;
		for (int i = 0; i < n; ++i)
		{
			deg[i] = atan2(ch[i].y - p.y, ch[i].x - p.x);
			while (i > 0 && deg[i] < deg[i - 1])
			{
				deg[i] += pi * 2;
			}
		}
		int Q;
		scanf("%d", &Q);
		while (Q--)
		{
			Point t;
			scanf("%lf %lf", &t.x, &t.y);
			double d = atan2(t.y - p.y, t.x - p.x);
			while (d < deg[0])
			{
				d += pi * 2;
			}
			int pos = lower_bound(deg, deg + n, d) - deg;
			if (dcmp(Cross(ch[pos - 1] - ch[pos % n], t - ch[pos % n])) > 0)
			{
				puts("n");
			}
			else
			{
				puts("y");
			}
		}
	}
	return 0;
}
