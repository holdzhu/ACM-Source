#include <cstdio>
#include <cmath>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		double mind = 1e9;
		double last;
		scanf("%lf", &last);
		n--;
		while (n--)
		{
			double t;
			scanf("%lf", &t);
			if (fabs(t - last) < fabs(mind))
			{
				mind = t - last;
			}
			last = t;
		}
		printf("%.2lf\n", mind);
	}
	return 0;
}
