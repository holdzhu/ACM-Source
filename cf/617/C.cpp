#include <cstdio>
#include <algorithm>

using namespace std;

long long x[2000], y[2000];

long long dis(long long dx, long long dy)
{
	return dx * dx + dy * dy;
}

int main()
{
	int n;
	long long x1, y1, x2, y2;
	scanf("%d %I64d %I64d %I64d %I64d", &n, &x1, &y1, &x2, &y2);
	for (int i = 0; i < n; ++i)
	{
		scanf("%I64d %I64d", &x[i], &y[i]);
	}
	long long ans = 1e18;
	for (int i = 0; i < n; ++i)
	{
		long long r1 = dis(x[i] - x1, y[i] - y1);
		long long r2 = 0;
		for (int j = 0; j < n; ++j)
		{
			long long d1 = dis(x[j] - x1, y[j] - y1);
			long long d2 = dis(x[j] - x2, y[j] - y2);
			if (d1 > r1)
				r2 = max(r2, d2);
		}
		ans = min(ans, r1 + r2);
	}
	long long r2 = 0;
	for (int j = 0; j < n; ++j)
	{
		long long d2 = dis(x[j] - x2, y[j] - y2);
		r2 = max(r2, d2);
	}
	printf("%I64d\n", min(ans, r2));
	return 0;
}
