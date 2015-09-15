#include <cstdio>
#include <algorithm>

using namespace std;

int cnt[1000001];
int p[1000000];

bool cmp(const int& a, const int& b)
{
	return cnt[a] > cnt[b];
}

int main()
{
	int n;
	scanf("%d", &n);
	int tp = 0;
	int mx = 0;
	for (int i = 0; i < n; ++i)
	{
		int t;
		scanf("%d", &t);
		mx = max(mx, t);
		if (cnt[t] == 0)
		{
			p[tp++] = t;
		}
		cnt[t]++;
	}
	sort(p, p + tp, cmp);
	if (cnt[p[0]] * 2 - 1 > n)
	{
		printf("-1\n");
		return 0;
	}
	int k = 0;
	int mi[2];
	for (mi[0] = 1; mi[0] <= mx && cnt[mi[0]] == 0; ++mi[0]);
	for (mi[1] = mi[0] + 1; mi[0] <= mx && cnt[mi[1]] == 0; ++mi[1]);
	bool cur = 0;
	int i;
	for (i = 0; i < n; ++i)
	{
		if (cnt[mi[cur]] == 0)
		{
			for (mi[cur] = mi[!cur] + 1; mi[cur] <= mx && cnt[mi[cur]] == 0; ++mi[cur]);
		}
		if (cnt[p[k]] * 2 - 1 >= n - i)
		{
			break;
		}
		printf("%d ", mi[cur]);
		cnt[mi[cur]]--;
		while (k < tp && (mi[cur] == p[k] || cnt[p[k]] == 0))
		{
			k++;
		}
		cur = !cur;
	}
	if (i != n)
	{
		int m = 0;
		for (int i = 0; i < cnt[p[k]] - 1; ++i)
		{
			printf("%d ", p[k]);
			while (cnt[m] == 0 || m == p[k])
			{
				m++;
			}
			printf("%d ", m);
			cnt[m]--;
		}
		printf("%d ", p[k]);
	}
	puts("");
	return 0;
}
