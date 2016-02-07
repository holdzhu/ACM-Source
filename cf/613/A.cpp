#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const double pi = acos(-1);

double px[100005];
double py[100005];

int main()
{
	int n;
	double x, y;
	scanf("%d", &n);
	scanf("%lf %lf", &x, &y);
	double l = 1e10, r = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%lf %lf", &px[i], &py[i]);
		double dis = hypot(px[i] - x, py[i] - y);
		l = min(l, dis);
		r = max(r, dis);
	}
	px[n] = px[0];
	py[n] = py[0];
	for (int i = 0; i < n; ++i)
	{
		double dx = px[i + 1] - px[i];
		double dy = py[i + 1] - py[i];
		if (dx == 0 && dy == 0) continue;
		double dis = fabs(dy * x - dx * y - (dy * px[i] - dx * py[i])) / hypot(dx, dy);
		double dis1 = hypot(px[i] - x, py[i] - y);
		double dis2 = hypot(px[i + 1] - x, py[i + 1] - y);
		if (dis1 >= dis2 && (px[i + 1] - x) * dx + (py[i + 1] - y) * dy > 0 || dis2 >= dis1 && (px[i] - x) * dx + (py[i] - y) * dy < 0)
		{
			l = min(l, dis);
		}
	}
	printf("%.10f\n", (r * r - l * l) * pi);
	return 0;
}
