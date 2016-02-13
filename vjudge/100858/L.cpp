#include <cstdio>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

const double eps = 1e-10;
const double pi = acos(-1);
double x[30000];
pair<double, double> deg[60000];

int main()
{
	int n;
	double alpha;
	while (scanf("%d %lf", &n, &alpha) == 2)
	{
		for (int i = 0; i < n; ++i)
			scanf("%lf", x + i);
		for (int i = 0; i < n; ++i)
		{
			double y;
			scanf("%lf", &y);
			double beta = atan2(y, x[i]);
			double t = 2 * alpha * hypot(x[i], y);
			double theta = acos((sqrt(1 + t * t) - 1) / t);
			deg[i].first = beta - theta;
			deg[i].second = beta + theta;
		}
		sort(deg, deg + n);
		for (int i = 0; i < n; ++i)
		{
			deg[i + n] = deg[i];
			deg[i + n].first += 2 * pi;
			deg[i + n].second += 2 * pi;
		}
		int ans = 0;
		priority_queue<double> pq;
		for (int i = 0; i < n * 2; ++i)
		{
			while (pq.size() && -pq.top() < deg[i].first - eps) pq.pop();
			pq.push(-deg[i].second);
			ans = max(ans, (int)pq.size());
		}
		printf("%d daze\n", ans);
	}
	return 0;
}
