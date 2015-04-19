#include <cstdio>
#include <cmath>

const double pi = acos(-1);
int N;
int W;
int divisor[7];
double x[30000];
double sx[30001];
int n;

inline double getWidth(int dis)
{
	return 2000 * sin(pi * dis / N);
}

bool check(double mx)
{
	int l = 0;
	int r = 0;
	int minvalue = n;
	int minindex = 0;
	double value = 0;
	while (l < n)
	{
		while (value + x[r] <= mx)
		{
			value += x[r++];
		}
		if (r - l < minvalue)
		{
			minvalue = r - l;
			minindex = l;
		}
		value -= x[l++];
	}
	for (int i = minindex; i <= minindex + minvalue; ++i)
	{
		int l = i;
		int r = i;
		for (int j = 0; j < W && r - i < n; ++j)
		{
			r += minvalue;
			value = sx[r] - sx[l];
			while (value + x[r] <= mx)
			{
				value += x[r++];
			}
			l = r = r + 1;
		}
		if (r - i >= n)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	while (scanf("%d", &W) == 1 && W)
	{
		scanf("%d", &N);
		int D;
		scanf("%d", &D);
		for (int i = 0; i < D; ++i)
		{
			scanf("%d", &divisor[i]);
		}
		n = 0;
		int last = 0;
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 0; j < D; ++j)
			{
				if (i % divisor[j] == 0)
				{
					x[n++] = getWidth(i - last);
					last = i;
					break;
				}
			}
		}
		for (int i = 0; i < n; ++i)
		{
			x[n + i] = x[i];
		}
		for (int i = 0; i < n; ++i)
		{
			x[n * 2 + i] = x[i];
		}
		sx[0] = 0;
		for (int i = 0; i < n * 3; ++i)
		{
			sx[i + 1] = sx[i] + x[i];
		}
		double L = 0;
		double R = 2000 * pi;
		while (1)
		{
			if (R - L <= 1e-5)
			{
				break;
			}
			double M = (R + L) / 2;
			if (check(M))
			{
				R = M;
			}
			else
			{
				L = M;
			}
		}
		printf("%.1f\n", L + 2000);
	}
	return 0;
}
