#include <cstdio>
#include <algorithm>

using namespace std;

long long exgcd(long long a, long long b, long long& x, long long& y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	long long d = exgcd(b, a % b, y, x);
	y -= x * (a / b);
	return d;
}

struct Point
{
	long long x, y;
	Point(long long x = 0, long long y = 0) : x(x), y(y) {}
};

typedef Point Vector;

Vector operator - (Point A, Point B)
{
	return Vector(A.x - B.x, A.y - B.y);
}

long long Cross(Vector A, Vector B)
{
	return A.x * B.y - A.y * B.x;
}

Point p[100000];

int main()
{
	int N;
	scanf("%d", &N);
	N--;
	double _S;
	scanf("%lf", &_S);
	long long S = _S * 2 + 0.5;
	for (int i = 0; i < N; ++i)
	{
		scanf("%I64d %I64d", &p[i].x, &p[i].y);
	}
	for (int i = 2; i < N; ++i)
	{
		S -= Cross(p[i - 1] - p[0], p[i] - p[0]);
	}
	for (int i = 0; i < N; ++i)
	{
		Point& p1 = p[(i + 1) % N];
		Point& p2 = p[i];
		Point& p0 = p[(i + 2) % N];
		Point& p3 = p[(i - 1 + N) % N];
		long long a = p1.y - p2.y;
		long long b = p2.x - p1.x;
		long long x, y;
		long long d = exgcd(a, b, x, y);
		long long s = S + Cross(p2, p1);
		if (s % d == 0)
		{
			x *= s / d;
			y *= s / d;
			long long kx = b / d;
			long long ky = -a / d;
			int l, r;
			if (Cross(p1 - p0, Vector(kx, ky)) > 0)
			{
				kx = -kx;
				ky = -ky;
			}
			l = -8000000;
			r = 8000000;
			while (l < r)
			{
				int m = (l + r) >> 1;
				Point t(x + kx * m, y + ky * m);
				if (Cross(t - p1, p1 - p0) > 0)
				{
					r = m;
				}
				else
				{
					l = m + 1;
				}
			}
			while (1)
			{
				Point t(x + kx * l, y + ky * l);
				if (Cross(t - p2, p2 - p3) >= 0 || Cross(t - p1, p1 - p0) <= 0)
				{
					break;
				}
				if (abs(t.x) <= 1000000 && abs(t.y) <= 1000000)
				{
					printf("%I64d %I64d\n", t.x, t.y);
					return 0;
				}
				l++;
			}
		}
	}
}
