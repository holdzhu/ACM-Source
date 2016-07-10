#include <cstdio>
#include <algorithm>

using namespace std;

struct Query
{
	int a, b, id;
	void read(int id)
	{
		scanf("%d %d", &a, &b);
		this->id = id;
	}
	bool operator < (const Query& rhs) const
	{
		return a < rhs.a;
	}
};

const int maxn = 400010;

int h[maxn];
int dp[maxn];
Query q[maxn];
int left[maxn];
int leftq[maxn];
int must[maxn];
int ans[maxn];
int id[maxn];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &h[i]);
	for (int i = 0; i < m; ++i)
		q[i].read(i);
	sort(q, q + m);
	fill(dp, dp + n + 1, 2e9);
	for (int i = 1, j = 0; i <= n; ++i)
	{
		while (j < m && q[j].a <= i)
		{
			leftq[j] = lower_bound(dp, dp + i, q[j].b) - dp;
			j++;
		}
		dp[left[i] = lower_bound(dp, dp + i, h[i]) - dp] = h[i];
	}
	int len = find(dp, dp + n, 2e9) - dp;
	fill(dp, dp + n, 2e9);
	for (int i = n, j = m - 1; i >= 1; --i)
	{
		while (j >= 0 && q[j].a >= i)
		{
			ans[q[j].id] = lower_bound(dp, dp + n - i, -q[j].b) - dp + leftq[j] + 1;
			j--;
		}
		int pos = lower_bound(dp, dp + n - i, -h[i]) - dp;
		if (pos + left[i] + 1 == len)
		{
			if (id[pos] == 0)
				id[pos] = i;
			else
				id[pos] = -1;
		}
		dp[pos] = -h[i];
	}
	for (int i = 0; i < len; ++i)
		if (id[i] > 0)
			must[id[i]] = 1;
	for (int i = 0; i < m; ++i)
		ans[q[i].id] = max(ans[q[i].id], len - must[q[i].a]);
	for (int i = 0; i < m; ++i)
		printf("%d\n", ans[i]);
	return 0;
}
