#include <cstdio>

int l[100001], r[100001];

int main()
{
	double ans = 0;
	int n, p;
	scanf("%d %d", &n, &p);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d", &l[i], &r[i]);
	}
	l[n] = l[0];
	r[n] = r[0];
	for (int i = 0; i < n; ++i)
	{
		int c1 = r[i] / p - (l[i] - 1) / p;
		int c2 = r[i + 1] / p - (l[i + 1] - 1) / p;
		ans += 2000.0 * (1.0 - 1.0 * (r[i] - l[i] + 1 - c1) * (r[i + 1] - l[i + 1] + 1 - c2) / (r[i] - l[i] + 1) / (r[i + 1] - l[i + 1] + 1));
	}
	printf("%.10f\n", ans);
	return 0;
}
