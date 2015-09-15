#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>

using namespace std;

const double eps = 1e-5;
int dcmp(double x)
{
    if (fabs(x) < eps) return 0;
    return x > 0 ? 1 : -1;
}

struct Point3
{
    double x, y, z;
    Point3(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
    bool operator == (const Point3& rhs) const
    {
    	return x == rhs.x && y == rhs.y && z == rhs.z;
    }
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

Vector3 e(Vector3 A)
{
    double len = sqrt(Dot(A, A));
    return Vector3(A.x / len, A.y / len, A.z / len);
}

Vector3 Cross(Vector3 A, Vector3 B)
{
    return Vector3(A.y * B.z - A.z * B.y, A.z * B.x - A.x * B.z, A.x * B.y - A.y * B.x);
}

double DistanceToLine(Point3 P, Point3 A, Point3 B)
{
	Vector3 v1 = B - A, v2 = P - A;
	return Length(Cross(v1, v2)) / Length(v1);
}

Point3 Mirror(Point3 A, Point3 B, Point3 P)
{
	double l1 = DistanceToLine(P, A, B);
	double l2 = Length(P - A);
	double l3 = sqrt(l2 * l2 - l1 * l1);
	if (Dot(B - A, P - A) >= 0)
	{
		return P + (A + e(B - A) * l3 - P) * 2;
	}
	else
	{
		return P + (A - e(B - A) * l3 - P) * 2;
	}
}

Point3 p[4];
Point3 ans[2];

int main()
{
	srand((int)time(0));
	bool flag = true;
	while (flag)
	{
		ofstream fout("E.in");
		for (int i = 0; i < 4; ++i)
		{
			p[i].x = rand() % 2000 - 1000;
			p[i].y = rand() % 2000 - 1000;
			p[i].z = rand() % 2000 - 1000;
		}
		if (p[0] == p[1] || p[2] == p[3])
		{
			continue;
		}
		for (int i = 0; i < 4; ++i)
		{
			fout << p[i].x << " " << p[i].y << " " << p[i].z << "\n";
		}
		fout.close();
		system("E.exe < E.in > E.out");
		ifstream fin("E.out");
		for (int i = 0; i < 2; ++i)
		{
			fin >> ans[i].x >> ans[i].y >> ans[i].z;
			assert(fabs(ans[i].x) <= 2000);
			assert(fabs(ans[i].y) <= 2000);
			assert(fabs(ans[i].z) <= 2000);
		}
		fin.close();
		Point3 Ai = Mirror(ans[0], ans[1], p[0]);
		Point3 Bi = Mirror(ans[0], ans[1], p[1]);
		printf("%.2f %.2f %.2f\n", Ai.x, Ai.y, Ai.z);
		printf("%.2f %.2f %.2f\n", Bi.x, Bi.y, Bi.z);
		double d1 = DistanceToLine(Ai, p[2], p[3]);
		double d2 = DistanceToLine(Bi, p[2], p[3]);
		printf("%.2f %.2f\n", d1, d2);
		assert(dcmp(d1) == 0 && dcmp(d2) == 0);
	}
	return 0;
}
