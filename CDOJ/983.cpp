#include <cstdio>
#include <cmath>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, a, b;
		scanf("%d %d %d", &n, &a, &b);
		int c[n];
		int pos = 0;
		int s = 0;
		while (n--)
		{
			int t;
			scanf("%d", &t);
			if (t >= a && t <= b)
			{
				c[pos++] = t;
				s += t;
			}
		}
		double A = s * 1.0 / pos;
		double S = 0;
		for (int i = 0; i < pos; ++i)
		{
			S += (c[i] - A) * (c[i] - A);
		}
		S = sqrt(S);
		S /= pos;
		printf("%.2lf %.2lf\n", A, S);
	}
	return 0;
}
