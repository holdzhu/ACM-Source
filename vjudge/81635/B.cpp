#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const double pi = acos(-1);
const double eps = 1e-9;

struct Point
{
	double x, y;
	int flag;
	int ID;
	bool operator < (const Point& rhs) const
	{
		return atan2(y, x) < atan2(rhs.y, rhs.x);
	}
};

typedef Point Vector;

double randeps()
{
	return rand() * eps * 2 / RAND_MAX - eps;
}

Vector operator - (const Point& A, const Point& B)
{
	return (Vector){A.x - B.x, A.y - B.y};
}

Vector operator * (const double& k, const Vector& A)
{
	return (Vector){A.x * k, A.y * k};
}

Point operator + (const Point& A, const Vector& B)
{
	return (Point){A.x + B.x, A.y + B.y};
}

double dot(const Vector& A, const Vector& B)
{
	return A.x * B.x + A.y * B.y;
}

double cross(const Vector& A, const Vector& B)
{
	return A.x * B.y - A.y * B.x;
}

double len(const Vector& A)
{
	return sqrt(dot(A, A));
}

double dis(const Point& A, const Point& B)
{
	return fabs(cross(B - A, A) / len(B - A));
}

double angle(const Vector& A, const Vector& B)
{
	double a = atan2(A.y, A.x);
	double b = atan2(B.y, B.x);
	double res = a - b;
	if (res < 0)
	{
		res += pi * 2;
	}
	return res;
}

double solve1(const double& a, const double& b, const double& c)
{
	return (-b - sqrt(b * b - 4 * a * c)) / 2 / a;
}

double solve2(const double& a, const double& b, const double& c)
{
	return (-b + sqrt(b * b - 4 * a * c)) / 2 / a;
}

int R, N;
Point p[100];
int nxt[100];

int main()
{
	scanf("%d", &R);
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%lf %lf", &p[i].x, &p[i].y);
		// p[i].x += randeps();
		// p[i].y += randeps();
		p[i].flag = 0;
	}
	double anglesum = 0;
	for (int i = 0; i < N; ++i)
	{
		anglesum += angle(p[i] - p[(i + 1) % N], p[(i + 2) % N] - p[(i + 1) % N]);
	}
	if (anglesum > N * pi)
	{
		for (int i = 0; i < (N - 1) / 2; ++i)
		{
			Point t = p[i + 1];
			p[i + 1] = p[N - 1 - i];
			p[N - 1 - i] = t;
		}
	}
	vector<Point> splitPoint;
	vector<Point> circlePoint;
	int outsideID = -1;
	double maxr = R;
	for (int i = 0; i < N; ++i)
	{
		Point A = p[i];
		Point B = p[(i + 1) % N];
		splitPoint.push_back(A);
		splitPoint[splitPoint.size() - 1].ID = splitPoint.size() - 1;
		if (maxr < len(A))
		{
			outsideID = splitPoint.size() - 1;
			maxr = len(A);
		}
		if (len(A) < R && len(B) >= R)
		{
			double k = solve2(dot(B - A, B - A), 2 * dot(A, B - A), dot(A, A) - R * R);
			splitPoint.push_back(A + k * (B - A));
			splitPoint[splitPoint.size() - 1].flag = 2;
			splitPoint[splitPoint.size() - 1].ID = splitPoint.size() - 1;
			circlePoint.push_back(splitPoint[splitPoint.size() - 1]);
		}
		else if (len(A) >= R && len(B) < R)
		{
			double k = solve1(dot(B - A, B - A), 2 * dot(A, B - A), dot(A, A) - R * R);
			splitPoint.push_back(A + k * (B - A));
			splitPoint[splitPoint.size() - 1].flag = 1;
			splitPoint[splitPoint.size() - 1].ID = splitPoint.size() - 1;
			circlePoint.push_back(splitPoint[splitPoint.size() - 1]);
		}
		else if (len(A) >= R && len(B) >= R && dis(A, B) <= R)
		{
			double k1 = solve1(dot(B - A, B - A), 2 * dot(A, B - A), dot(A, A) - R * R);
			double k2 = solve2(dot(B - A, B - A), 2 * dot(A, B - A), dot(A, A) - R * R);
			splitPoint.push_back(A + k1 * (B - A));
			splitPoint[splitPoint.size() - 1].flag = 1;
			splitPoint[splitPoint.size() - 1].ID = splitPoint.size() - 1;
			circlePoint.push_back(splitPoint[splitPoint.size() - 1]);
			splitPoint.push_back(A + k2 * (B - A));
			splitPoint[splitPoint.size() - 1].flag = 2;
			splitPoint[splitPoint.size() - 1].ID = splitPoint.size() - 1;
			circlePoint.push_back(splitPoint[splitPoint.size() - 1]);
		}
	}
	sort(circlePoint.begin(), circlePoint.end());
	for (int i = 0; i < circlePoint.size(); ++i)
	{
		nxt[circlePoint[i].ID] = circlePoint[(i + 1) % circlePoint.size()].ID;
	}
	if (outsideID == -1)
	{
		printf("%.4f\n", 2 * pi * R);
	}
	else
	{
		double ans = 0;
		int t = outsideID;
		while (1)
		{
			if (splitPoint[t].flag == 0 || splitPoint[t].flag == 2)
			{
				ans += len(splitPoint[(t + 1) % splitPoint.size()] - splitPoint[t]);
				t = (t + 1) % splitPoint.size();
			}
			else
			{
				double ttt = fabs(asin(len(splitPoint[nxt[t]] - splitPoint[t]) / 2 / R) * 2 * R);
				if (cross(splitPoint[nxt[t]] - splitPoint[t], splitPoint[t]) > 0)
				{
					ttt = 2 * R * pi - ttt;
				}
				ans += ttt;
				t = nxt[t];
			}
			if (splitPoint[t].x == splitPoint[outsideID].x && splitPoint[t].y == splitPoint[outsideID].y)
			{
				break;
			}
		}
		printf("%.4f\n", ans);
	}
	return 0;
}
