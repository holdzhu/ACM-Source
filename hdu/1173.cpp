#include <cstdio>
#include <algorithm>

using namespace std;

double x[1000000], y[1000000];

int main()
{
	int n;
	while (scanf("%d", &n) == 1 && n)
	{
		for (int i = 0; i < n; ++i)
		{
			scanf("%lf %lf", &x[i], &y[i]);
		}
		sort(x, x + n);
		sort(y, y + n);
		printf("%.2lf %.2lf\n", x[n / 2], y[n / 2]);
	}
	return 0;
}
