#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
int a[200010];

double solve(double x)
{
	double res = 0;
	double mx = 0;
	double mi = 0;
	double sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += a[i] - x;
		if (sum > mx)
		{
			mx = sum;
		}
		if (sum < mi)
		{
			mi = sum;
			mx = sum;
		}
		res = max(res, mx - mi);
	}
	mx = 0;
	mi = 0;
	sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += x - a[i];
		if (sum > mx)
		{
			mx = sum;
		}
		if (sum < mi)
		{
			mi = sum;
			mx = sum;
		}
		res = max(res, mx - mi);
	}
	return res;
}

int main()
{
	scanf("%d", &n);
	double l = 1e23;
	double r = -1e23;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
		l = min(l, 1.0 * a[i]);
		r = max(r, 1.0 * a[i]);
	}
	for (int it = 0; it < 100; ++it)
	{
		double m1 = (r - l) / 3 + l;
		double m2 = l + r - m1;
		double s1 = solve(m1);
		double s2 = solve(m2);
		if (s1 > s2)
		{
			l = m1;
		}
		else
		{
			r = m2;
		}
	}
	printf("%.8f\n", solve(l));
	return 0;
}
