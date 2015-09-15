#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

const double eps = 1e-10;
int dcmp(double x)
{
	if (fabs(x) < eps)
	{
		return 0;
	}
	return x > 0 ? 1 : -1;
}

struct Point
{
	double x, y;
	Point(double x = 0, double y = 0) : x(x), y(y) {}
};

struct Polygon
{
	vector<Point> p;
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

Vector operator * (Point A, double k)
{
	return Vector(A.x * k, A.y * k);
}

bool operator == (Point A, Point B)
{
	return dcmp(A.x - B.x) == 0 && dcmp(A.y - B.y) == 0;
}

double Dot(Vector A, Vector B)
{
	return A.x * B.x + A.y * B.y;
}

double Cross(Vector A, Vector B)
{
	return A.x * B.y - A.y * B.x;
}

Vector Rotate90(Vector A)
{
	return Vector(-A.y, A.x);
}

bool SegmentProperIntersection(Point a1, Point a2, Point b1, Point b2)
{
	double c1 = Cross(a2 - a1, b1 - a1), c2 = Cross(a2 - a1, b2 - a1),
		   c3 = Cross(b2 - b1, a1 - b1), c4 = Cross(b2 - b1, a2 - b1);
	return dcmp(c1) * dcmp(c2) < 0 && dcmp(c3) * dcmp(c4) < 0;
}

bool OnSegment(Point p, Point a1, Point a2)
{
	return dcmp(Cross(a1 - p, a2 - p)) == 0 && dcmp(Dot(a1 - p, a2 - p)) < 0;
}

bool HitTest(Polygon A, Polygon B)
{
	for (int i = 0; i < A.p.size(); ++i)
	{
		for (int j = 0; j < B.p.size(); ++j)
		{
			Point& a1 = A.p[i];
			Point& a2 = A.p[(i + 1) % A.p.size()];
			Point& b1 = B.p[j];
			Point& b2 = B.p[(j + 1) % B.p.size()];
			if (SegmentProperIntersection(a1, a2, b1, b2) ||
				OnSegment(a1, b1, b2) || OnSegment(b1, a1, a2) ||
				a1 == b1)
			{
				return true;
			}
		}
	}
	return false;
}

Point ReadPoint()
{
	Point t;
	scanf(" (%lf,%lf)", &t.x, &t.y);
	return t;
}

Polygon poly[128];

int main()
{
	while (1)
	{
		char ch[2], type[10];
		scanf("%s", ch);
		if (ch[0] == '-')
		{
			for (int i = 'A'; i <= 'Z'; ++i)
			{
				if (poly[i].p.size() == 0)
				{
					continue;
				}
				vector<char> in;
				for (int j = 'A'; j <= 'Z'; ++j)
				{
					if (i != j && HitTest(poly[i], poly[j]))
					{
						in.push_back(j);
					}
				}
				if (in.size() == 0)
				{
					printf("%c has no intersections\n", i);
				}
				else
				{
					printf("%c intersects with ", i);
					if (in.size() == 1)
					{
						putchar(in[0]);
					}
					else if (in.size() == 2)
					{
						printf("%c and %c", in[0], in[1]);
					}
					else
					{
						for (int j = 0; j < in.size() - 1; ++j)
						{
							printf("%c, ", in[j]);
						}
						printf("and %c", in.back());
					}
					puts("");
				}
			}
			puts("");
			for (int i = 'A'; i <= 'Z'; ++i)
			{
				poly[i].p.clear();
			}
			continue;
		}
		if (ch[0] == '.')
		{
			break;
		}
		scanf("%s", type);
		if (type[0] == 's')
		{
			Point A = ReadPoint();
			Point B = ReadPoint();
			Point M = (A + B) * 0.5;
			poly[ch[0]].p.push_back(A);
			poly[ch[0]].p.push_back(M + Rotate90(A - M));
			poly[ch[0]].p.push_back(B);
			poly[ch[0]].p.push_back(M + Rotate90(B - M));
		}
		else if (type[0] == 'r')
		{
			Point A = ReadPoint();
			Point B = ReadPoint();
			Point C = ReadPoint();
			poly[ch[0]].p.push_back(A);
			poly[ch[0]].p.push_back(B);
			poly[ch[0]].p.push_back(C);
			poly[ch[0]].p.push_back(A + C - B);
		}
		else if (type[0] == 'l')
		{
			for (int i = 0; i < 2; ++i)
			{
				poly[ch[0]].p.push_back(ReadPoint());
			}
		}
		else if (type[0] == 't')
		{
			for (int i = 0; i < 3; ++i)
			{
				poly[ch[0]].p.push_back(ReadPoint());
			}
		}
		else if (type[0] == 'p')
		{
			int n;
			scanf("%d", &n);
			for (int i = 0; i < n; ++i)
			{
				poly[ch[0]].p.push_back(ReadPoint());
			}
		}
	}
	return 0;
}
