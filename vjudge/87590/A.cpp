#include <cstdio>
#include <cstring>

int ans[5001];
long long u[5000];
long long v[5000];

int main()
{
	int n, m;
	long long x1, y1, x2, y2;
	while (scanf("%d %d %I64d %I64d %I64d %I64d", &n, &m, &x1, &y1, &x2, &y2) == 6 && n)
	{
		memset(ans, 0, sizeof ans);
		for (int i = 0; i < n; ++i)
		{
			scanf("%I64d %I64d", &u[i], &v[i]);
		}
		while (m--)
		{
			long long x, y;
			scanf("%I64d %I64d", &x, &y);
			int l = 0;
			int r = n;
			while (l < r)
			{
				int m = (l + r) >> 1;
				if ((y1 - y2) * x < (y1 - y) * (v[m] - u[m]) + (y1 - y2) * u[m])
				{
					r = m;
				}
				else
				{
					l = m + 1;
				}
			}
			ans[l]++;
		}
		for (int i = 0; i <= n; ++i)
		{
			printf("%d: %d\n", i, ans[i]);
		}
		puts("");
	}
	return 0;
}
