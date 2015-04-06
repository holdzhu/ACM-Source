#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		double s = 0;
		double mind = 1e9;
		double maxd = -1;
		for (int i = 0; i < n; ++i)
		{
			double t;
			scanf("%lf", &t);
			s += t;
			if (mind > t)
			{
				mind = t;
			}
			if (maxd < t)
			{
				maxd = t;
			}
		}
		printf("%.2lf\n", (s - mind - maxd) / (n - 2));
	}
	return 0;
}
