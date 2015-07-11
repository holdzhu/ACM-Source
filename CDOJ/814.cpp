#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point
{
	double x, y;
};

typedef Point Vector;

Vector operator - (const Point& A, const Point& B)
{
	return (Vector){A.x - B.x, A.y - B.y};
}

inline double dot(const Vector& A, const Vector& B)
{
	return A.x * B.x + A.y * B.y;
}

inline double cross(const Vector& A, const Vector& B)
{
	return A.x * B.y - A.y * B.x;
}

inline double length(const Vector& A)
{
	return sqrt(dot(A, A));
}

int N;
Point P[20];
Point G[2];

bool lineCoverd(Point A, Point B, double R)
{
	double l[2], r[2];
	double Lab = length(B - A);
	for (int i = 0; i < 2; ++i)
	{
		double d = fabs(cross(B - A, G[i] - A) / Lab);
		if (d >= R)
		{
			l[i] = r[i] = 0;
			continue;
		}
		double L = dot(B - A, G[i] - A) / Lab;
		double delta = sqrt(R * R - d * d);
		l[i] = L - delta;
		r[i] = L + delta;
		if (l[i] <= 0 && r[i] >= Lab)
		{
			return true;
		}
	}
	for (int i = 0; i < 2; ++i) 
	{
		if (l[i] <= 0 && r[!i] >= Lab && r[i] >= l[!i])
		{
			return true;
		}
	}
	return false;
}

bool solve(double R)
{
	for (int i = 0; i < N; ++i)
	{
		if (!lineCoverd(P[i], P[(i + 1) % N], R))
		{
			return false;
		}
	}
	return true;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%lf %lf", &P[i].x, &P[i].y);
	}
	for (int i = 0; i < 2; ++i)
	{
		scanf("%lf %lf", &G[i].x, &G[i].y);
	}
	double L = 0;
	double R = 3000;
	while (R - L > 0.00001)
	{
		double M = (L + R) / 2;
		if (solve(M))
		{
			R = M;
		}
		else
		{
			L = M;
		}
	}
	printf("%.3f\n", L);
	return 0;
}