#include <cstdio>
#include <cmath>

double v[100];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		printf("0 ");
	puts("");
	double t = 0, d = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j + 1 < i; ++j)
			printf("%.10f ", v[j]);
		if (i)
		{
			double a = (v[i - 1] * v[i - 1] - d * d) / 2 / v[i - 1];
			printf("%.10f ", a), t += a * a, d = v[i - 1] - a;
			v[i - 1] = a;
		}
		printf("%.10f ", v[i] = sqrt(1 - t));
		for (int j = i + 1; j < n; ++j)
			printf("0 ");
		puts("");
	}
	return 0;
}
