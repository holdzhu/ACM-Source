#include <cstdio>
#include <cstring>
#include <functional>
#include <algorithm>

using namespace std;

int ans[1001];
int cnt[1001];
pair<long long, long long> p[1000];

int main()
{
	int n, m;
	long long x1, y1, x2, y2;
	while (scanf("%d %d %I64d %I64d %I64d %I64d", &n, &m, &x1, &y1, &x2, &y2) == 6 && n)
	{
		memset(ans, 0, sizeof ans);
		memset(cnt, 0, sizeof cnt);
		for (int i = 0; i < n; ++i)
		{
			scanf("%I64d %I64d", &p[i].first, &p[i].second);
		}
		sort(p, p + n);
		while (m--)
		{
			long long x, y;
			scanf("%I64d %I64d", &x, &y);
			int l = 0;
			int r = n;
			while (l < r)
			{
				int m = (l + r) >> 1;
				if ((y1 - y2) * x < (y1 - y) * (p[m].second - p[m].first) + (y1 - y2) * p[m].first)
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
			cnt[ans[i]]++;
		}
		puts("Box");
		for (int i = 1; i <= n; ++i)
		{
			if (cnt[i])
			{
				printf("%d: %d\n", i, cnt[i]);
			}
		}
	}
	return 0;
}
