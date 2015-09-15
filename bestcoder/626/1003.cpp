#include <cstdio>
#include <algorithm>

using namespace std;

int d[100001];
long double s[100001];
long double twos[100001];

int main()
{
	twos[0] = 1;
	for (int i = 1; i <= 100000; ++i)
	{
		twos[i] = twos[i - 1] * 2;
	}
	int n;
	while (scanf("%d", &n) == 1)
	{
		d[1] = 1;
		for (int i = 0; i < n - 1; ++i)
		{
			int f;
			scanf("%d", &f);
			d[i + 2] = d[f] + 1;
		}
		s[0] = 0;
		for (int i = 1; i <= n; ++i)
		{
			s[i] = d[i] * twos[i - 1] + s[i - 1];
		}
		sort(d + 1, d + n + 1);
		long double res = 0;
		long double cnt = twos[n] - n - 1;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = max(n - 1000, 1); j < i; ++j)
			{
				res += twos[j - 1] / cnt * d[i] * d[j] / (d[i] + d[j]);
			}
			if (n - 1000 > 1)
			{
				res += s[min(n - 1000, i) - 1] / cnt;
			}
		}
		double ans = res;
		printf("%.6f\n", ans);
	}
	return 0;
}
