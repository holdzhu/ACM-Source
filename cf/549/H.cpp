#include <cstdio>
#include <cmath>
#include <cfloat>
#include <algorithm>

using namespace std;

int main()
{
	long long a, b, c, d;
	scanf("%I64d %I64d %I64d %I64d", &a, &b, &c, &d);
	double FC = a * d - b * c;
	double ans = DBL_MAX;
	for (int A = -1; A <= 1; A += 2) for (int B = -1; B <= 1; B += 2) for (int C = -1; C <= 1; C += 2) for (int D = -1; D <= 1; D += 2)
	{
		long long FA = A * D - B * C;
		double FB = a * D + d * A - b * C - c * B;
		if (FA == 0)
		{
			ans = min(ans, fabs(-FC * 1.0 / FB));
		}
		else
		{
			double delta = FB * FB - 4.0 * FA * FC;
			if (delta >= 0)
			{
				double x1 = (-FB + sqrt(delta)) / 2 / FA;
				double x2 = (-FB - sqrt(delta)) / 2 / FA;
				ans = min(ans, fabs(x1));
				ans = min(ans, fabs(x2));
			}
		}
	}
	printf("%.10f\n", ans);
	return 0;
}
