#include <cstdio>

long long x[100000], y[100000];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%I64d %I64d", &x[i], &y[i]);
	}
	int id1 = -1;
	long long mi = 0;
	for (int i = 1; i < n; ++i)
	{
		long long dis = (x[i] - x[0]) * (x[i] - x[0]) + (y[i] - y[0]) * (y[i] - y[0]);
		if (id1 == -1 || mi > dis)
		{
			mi = dis;
			id1 = i;
		}
	}
	int id2 = -1;
	for (int i = 1; i < n; ++i)
	{
		long long dis = (x[i] - x[0]) * (x[i] - x[0]) + (y[i] - y[0]) * (y[i] - y[0]);
		long long cross = (x[i] - x[0]) * (y[id1] - y[0]) - (y[i] - y[0]) * (x[id1] - x[0]);
		if (cross && (id2 == -1 || mi > dis))
		{
			mi = dis;
			id2 = i;
		}
	}
	printf("1 %d %d\n", id1 + 1, id2 + 1);
	return 0;
}
