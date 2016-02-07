#include <cstdio>
#include <algorithm>

using namespace std;

pair<int, int> a[100000];
long long sum[100001];
int s[100000];

int main()
{
	int n, A, cf, cm;
	long long m;
	scanf("%d %d %d %d %I64d", &n, &A, &cf, &cm, &m);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i].first);
		a[i].second = i;
	}
	sort(a, a + n);
	sum[0] = 0;
	for (int i = 0; i < n; ++i)
	{
		sum[i + 1] = sum[i] + a[i].first;
	}
	pair<long long, pair<int, int> > ans;
	ans.first = -1;
	for (int i = 0; i <= n; ++i)
	{
		int l = 0, r = A;
		while (l < r)
		{
			int M = (l + r + 1) >> 1;
			int pos = lower_bound(a, a + n - i, make_pair(M, -1)) - a;
			if (1ll * M * pos - sum[pos] <= m)
			{
				l = M;
			}
			else
			{
				r = M - 1;
			}
		}
		ans = max(ans, make_pair(1ll * cf * i + 1ll * cm * l, make_pair(i, l)));
		if (i < n)
			m -= A - a[n - i - 1].first;
		if (m < 0)
			break;
	}
	printf("%I64d\n", ans.first);
	for (int i = 0; i < n; ++i)
	{
		if (i < n - ans.second.first)
		{
			s[a[i].second] = max(a[i].first, ans.second.second);
		}
		else
		{
			s[a[i].second] = A;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", s[i]);
	}
	printf("\n");
	return 0;
}
