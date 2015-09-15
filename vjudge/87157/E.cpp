#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const double eps = 1e-9;
int dcmp(double x)
{
	if (fabs(x) < eps) return 0;
	return x > 0 ? 1 : -1;
}

struct Point3
{
	double x, y, z;
	Point3(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
};

typedef Point3 Vector3;

Vector3 operator + (Vector3 A, Vector3 B)
{
	return Vector3(A.x + B.x, A.y + B.y, A.z + B.z);
}

Vector3 operator - (Point3 A, Point3 B)
{
	return Vector3(A.x - B.x, A.y - B.y, A.z - B.z);
}

Vector3 operator * (Vector3 A, double p)
{
	return Vector3(A.x * p, A.y * p, A.z * p);
}

double Dot(Vector3 A, Vector3 B)
{
	return A.x * B.x + A.y * B.y + A.z * B.z;
}

double Length(Vector3 A)
{
	return sqrt(Dot(A, A));
}

Vector3 Normal(Vector3 A)
{
	double L = Length(A);
	return Vector3(A.x / L, A.y / L, A.z / L);
}

Vector3 Cross(Vector3 A, Vector3 B)
{
	return Vector3(A.y * B.z - A.z * B.y, A.z * B.x - A.x * B.z, A.x * B.y - A.y * B.x);
}

bool isValid(Point3 A)
{
	return dcmp(A.x + 2000) >= 0 && dcmp(A.x - 2000) <= 0 &&
	dcmp(A.y + 2000) >= 0 && dcmp(A.y - 2000) <= 0 &&
	dcmp(A.z + 2000) >= 0 && dcmp(A.z - 2000) <= 0;
}

double LineDistance3D(Point3 p1, Vector3 u, Point3 p2, Vector3 v)
{
	double b = Dot(u, u) * Dot(v, v) - Dot(u, v) * Dot(u, v);
	double a = Dot(u, v) * Dot(v, p1 - p2) - Dot(v, v) * Dot(u, p1 - p2);
	return a / b;
}

bool solve(Point3 p, Vector3 s)
{
	if (!isValid(p) || !isValid(p + s))
	{
		return false;
	}
    printf("%.13f %.13f %.13f\n", p.x, p.y, p.z);
    printf("%.13f %.13f %.13f\n", (p + s).x, (p + s).y, (p + s).z);
    puts("180");
    return true;
}

int main()
{
	Point3 A, B, C, D;
	scanf("%lf %lf %lf", &A.x, &A.y, &A.z);
	scanf("%lf %lf %lf", &B.x, &B.y, &B.z);
	scanf("%lf %lf %lf", &C.x, &C.y, &C.z);
	scanf("%lf %lf %lf", &D.x, &D.y, &D.z);
	Vector3 v = Cross(B - A, D - C);
	if (dcmp(v.x) == 0 && dcmp(v.y) == 0 && dcmp(v.z) == 0)
	{
		Point3 Pa = (A + C) * 0.5;
		solve(Pa, B - A);
	}
	else
	{
		Point3 p = (A + (B - A) * LineDistance3D(A, B - A, C, D - C) + C + (D - C) * LineDistance3D(C, D - C, A, B - A)) * 0.5;
		if (!solve(p, Normal(B - A) + Normal(D - C)) && !solve(p, Normal(B - A) - Normal(D - C)))
		{
			while (1);
		}
	}
	return 0;
}
