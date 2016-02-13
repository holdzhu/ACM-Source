#include <cstdio>

int a[1000][1000];
int s[1000];

int main()
{
	int n, m;
	while (scanf("%d %d", &n, &m) == 2)
	{
		for (int i = 0; i < n; ++i)
		{
			s[i] = 0;
			for (int j = 0; j < m; ++j)
			{
				scanf("%d", &a[i][j]);
				s[i] += a[i][j];
			}
		}
		double ans = 0;
		for (int i = 0; i < m; ++i)
		{
			double S = 0;
			double S2 = 0;
			for (int j = 0; j < n; ++j)
			{
				double p = 1.0 * a[j][i] / s[j];
				S += p;
				S2 += p * p;
			}
			ans += S * S + S - S2;
		}
		printf("%.2f\n", ans);
	}
	return 0;
}
