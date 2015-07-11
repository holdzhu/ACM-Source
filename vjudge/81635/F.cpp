#include <cstdio>
#include <cmath>

struct Point
{
	double x, y;
};

const double g = 9.8;
Point p[10000];

double slope(const Point& A, const Point& B)
{
	return (B.y - A.y) / (B.x - A.x);
}

double len(const Point& A, const Point& B)
{
	return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

int main()
{
	int N;
	double V;
	scanf("%d %lf", &N, &V);
	for (int i = 0; i < N; ++i)
	{
		scanf("%lf %lf", &p[i].x, &p[i].y);
	}
	double ans = len(p[0], p[1]);
	int t = 1;
	while (t < N - 1)
	{
		if (slope(p[t - 1], p[t]) < slope(p[t], p[t + 1]))
		{
			ans += len(p[t], p[t + 1]);
			t++;
		}
		else
		{
			double vx = V * (p[t].x - p[t - 1].x) / len(p[t - 1], p[t]);
			double vy = V * (p[t].y - p[t - 1].y) / len(p[t - 1], p[t]);
			int f = t + 1;
			while (f < N)
			{
				double A = -0.5 * g / vx / vx;
				double B = vy / vx - slope(p[f], p[f - 1]);
				double C = p[t].y - p[f - 1].y + (p[f - 1].x - p[t].x) * slope(p[f], p[f - 1]);
				double x = (-B - sqrt(B * B - 4.0 * A * C)) / 2.0 / A;
				printf("%.10f\n", x);
				if (x > p[f].x - p[t].x)
				{
					f++;
				}
				else
				{
					ans += (p[f].x - p[t].x - x) / (p[f].x - p[f - 1].x) * len(p[f], p[f - 1]);
					break;
				}
			}
			t = f;
		}
	}
	printf("%.8f\n", ans);
	return 0;
}
