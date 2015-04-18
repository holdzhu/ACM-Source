#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

struct Point
{
	double x, y;
	Point(double x = 0, double y = 0): x(x), y(y) {}
	bool operator < (const Point& rhs) const
	{
		return x < rhs.x || (x == rhs.x && y < rhs.y);
	}
};

Point p[100];
int N;
const double pi = acos(-1);

Point operator - (Point A, Point B)
{
    return Point(A.x - B.x, A.y - B.y);
}

double Cross(Point A, Point B)
{
    return A.x * B.y - A.y * B.x;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		scanf("%d", &N);
		for (int i = 0; i < N; ++i)
		{
			scanf("%lf %lf", &p[i].x, &p[i].y);
		}
		printf("Case #%d:\n", kase);
		for (int i = 0; i < N; ++i)
		{
			vector<double> theta;
			theta.push_back(pi);
			for (int j = 0; j < N; ++j)
			{
				if (i != j)
				{
					double angle = atan2(p[j].x - p[i].x, p[j].y - p[i].y);
					theta.push_back(angle);
				}
			}
			sort(theta.begin(), theta.end());
			int ans = N - 1;
			printf("%dth\n", i);
			for (int j = 0; j < N - 1; ++j)
			{
				int r = upper_bound(theta.begin(), theta.end(), theta[j] + pi) - theta.begin();
				printf("%d %f %d %f\n", j, theta[j], r, theta[r]);
				ans = min(ans, (r - j));
				ans = min(ans, N - 1 - (r - j));
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
