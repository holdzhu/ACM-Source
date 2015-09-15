#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

long long x[200];
long long y[200];
long long t[200];

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i)
	{
		scanf("%I64d %I64d", &x[i], &y[i]);
	}
	double ans = n == 1 ? 0 : 1e23;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i != j)
			{
				int p = 0;
				long long dx = y[j] - y[i];
				long long dy = x[i] - x[j];
				long long c = dx * x[i] + dy * y[i];
				for (int k = 0; k < n; ++k)
				{
					long long d = dx * x[k] + dy * y[k] - c;
					if (d >= 0)
					{
						t[p++] = d;
					}
				}
				if (p >= k)
				{
					sort(t, t + p);
					ans = min(ans, t[k - 1] / sqrt(dx * dx + dy * dy));
				}
			}
		}
	}
	printf("%.10f\n", max(ans - 1, 0.));
	return 0;
}
