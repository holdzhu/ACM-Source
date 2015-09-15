#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
double x1[100];
double y1[100];
double x2[100];
double y2[100];

const double eps = 1e-8;

bool check(double a, double b)
{
	if (fabs(a) < eps && fabs(b) < eps)
	{
		return false;
	}
	double l = -1e34;
	double r = 1e34;
	for (int i = 0; i < n; ++i)
	{
		double mi = x1[i] * a + y1[i] * b;
		double mx = x2[i] * a + y2[i] * b;
		if (mi > mx)
		{
			swap(mi, mx);
		}
		l = max(l, mi);
		r = min(r, mx);
		if (l - r > eps)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%lf %lf %lf %lf", &x1[i], &y1[i], &x2[i], &y2[i]);
		}
		bool flag = n == 1;
		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				if (check(y2[j] - y1[i], x1[i] - x2[j]) || check(y2[i] - y1[j], x1[j] - x2[i]) ||
					check(y1[j] - y1[i], x1[i] - x1[j]) || check(y2[i] - y2[j], x2[j] - x2[i]))
				{
					flag = true;
					break;
				}
			}
		}
		puts(flag ? "Yes!" : "No!");
	}
	return 0;
}
