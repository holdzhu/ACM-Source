#include <cstdio>
#include <algorithm>

using namespace std;

double d(int x, int y)
{
	return x == 0 ? 1e11 : y * 1.0 / x;
}

int main()
{
	int N;
	scanf("%d", &N);
	int x[N], y[N];
	for (int i = 0; i < N; ++i)
	{
		scanf("%d %d", &x[i], &y[i]);
	}
	double d1 = d(x[1] - x[0], y[1] - y[0]);
	int d1count = 1;
	double d2;
	int d2count = 0;
	int d2index = 0;
	bool flag = false;
	for (int i = 2; i < N; ++i)
	{
		double t = d(x[i] - x[0], y[i] - y[0]);
		if (t == d1)
		{
			d1count++;
		}
		else
		{
			d2index = i;
			if (d2count)
			{
				if (t == d2)
				{
					d2count++;
				}
				else
				{
					flag = true;
					break;
				}
			}
			else
			{
				d2 = t;
				d2count = 1;
			}
		}
	}
	if (flag)
	{
		printf("%d %d\n", x[0], y[0]);
	}
	else if (d1count == 1)
	{
		printf("%d %d\n", x[1], y[1]);
	}
	else
	{
		printf("%d %d\n", x[d2index], y[d2index]);
	}
	return 0;
}
