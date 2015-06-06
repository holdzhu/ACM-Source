#include <cstdio>
#include <cmath>

int main()
{
	int n;
	double p;
	double s;
	double v;
	scanf("%d %lf %lf %lf", &n, &p, &s, &v);
	s /= 1e9;
	double c = 15.598261092309;
	printf("%.10f\n", s * (1e9 + 1e9 / c) / v);
	return 0;
}
