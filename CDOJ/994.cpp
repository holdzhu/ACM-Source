#include <cstdio>
#include <cmath>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int x1, y1, r1, x2, y2, r2;
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		int _l = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
		if (_l >= (r1 + r2) * (r1 + r2))
		{
			printf("0.00\n");
		}
		else if ((r1 - r2) * (r1 - r2) >= _l)
		{
			if (r2 > r1)
			{
				printf("%.2lf\n", r1 * r1 * 3.1415926535897932384626433832795);
			}
			else
			{
				printf("%.2lf\n", r2 * r2 * 3.1415926535897932384626433832795);
			}
		}
		else
		{
			double l = sqrt(_l);
			// double h = sqrt(r1 * r1 * 0.5 + r2 * r2 * 0.5 - l * l * 0.25 - ((r1 * r1 - r2 * r2) / l / 2) * ((r1 * r1 - r2 * r2) / l / 2));
			double x = (_l + r1 * r1 - r2 * r2) / l / 2;
			double t1 = acos(x / (r1 * 1.0));
			double t2 = acos((l - x) / r2);
			printf("%.2lf\n", r1 * r1 * t1 + r2 * r2 * t2 - l * r1 * sin(t1));
		}
	} 
	return 0;
}
