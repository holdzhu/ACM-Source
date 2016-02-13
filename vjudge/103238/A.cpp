#include <cstdio>

double p[51];

double solve(int k, int l, int r)
{
	if (k < l)
		return 1;
	if (k > r)
		return 0;
	long double A = 1;
	long double old = 0;
	for (int i = k - 1; i >= l; --i)
	{
		long double t = (A - old) / p[i] / (1 - p[i + 1]);
		old = A;
		A = t;
	}
	for (int i = k - 1; i >= l; --i)
		A *= p[i];
	A /= 1 - p[l];
	long double B = 1;
	old = 0;
	for (int i = k + 1; i <= r; ++i)
	{
		long double t = (B - old) / (1 - p[i]) / p[i - 1];
		old = B;
		B = t;
	}
	for (int i = k + 1; i <= r; ++i)
		B *= 1 - p[i];
	B /= p[r];
	printf("%.10f %.10f\n", (double)A, (double)B);
	return B / (A + B);
}

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 1; i < n; ++i)
		scanf("%lf", &p[i]);
	printf("%.10f\n", solve(k, 1, n - 1));
	printf("%.10f\n", solve(k, 2, n - 1) * (1 - solve(1, 1, n - 1))
		+ (1 - solve(k, 1, n - 2)) * solve(n - 1, 1, n - 1));
	return 0;
}
