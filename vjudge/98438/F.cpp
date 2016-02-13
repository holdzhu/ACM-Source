#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 2e5;
const int maxm = 1e5;
int a[maxn + 1];
int pos[maxn + 1];
int pre[maxn + 1];
int tree[maxn + 1];
int vis[maxn + 1];
int n, m;
int cnt[maxn + 1];
pair<int, int> q[maxm];
pair<int, int> tmp[maxm];
int tim = 0;

inline int lowbit(int x)
{
	return x & (-x);
}

void update(int x)
{
	while (x <= n)
	{
		if (vis[x] != tim)
		{
			vis[x] = tim;
			tree[x] = 0;
		}
		tree[x]++;
		x += lowbit(x);
	}
}

int query(int x)
{
	int ret = 0;
	while (x)
	{
		if (vis[x] != tim)
		{
			vis[x] = tim;
			tree[x] = 0;
		}
		ret += tree[x];
		x -= lowbit(x);
	}
	return ret;
}

void CDQ(int l, int r)
{
	if (r - l > 1)
	{
		int m = (l + r) >> 1;
		CDQ(l, m);
		copy(q + m, q + r, tmp + m);
		sort(tmp + l, tmp + m);
		sort(tmp + m, tmp + r);
		++tim;
		for (int i = l, j = m; j < r; ++j)
		{
			while (i < m && tmp[i].first < tmp[j].first)
			{
				update(pos[tmp[i].first]);
				++i;
			}
			cnt[tmp[j].second] += (i - l) - query(pos[tmp[j].first]);
		}
		++tim;
		for (int i = m - 1, j = r - 1; j >= m; --j)
		{
			while (i >= l && tmp[i].first > tmp[j].first)
			{
				update(pos[tmp[i].first]);
				--i;
			}
			cnt[tmp[j].second] += query(pos[tmp[j].first]);
		}
		CDQ(m, r);
	}
	else
	{
		tmp[l] = q[l];
	}
}

int main()
{
	while (scanf("%d %d", &n, &m) == 2)
	{
		long long ans = 0;
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d", a + i);
			pre[i] = query(a[i]) + 1;
			update(a[i]);
			pos[a[i]] = i;
			ans += i - pre[i];
		}
		for (int i = 0; i < m; ++i)
		{
			scanf("%d", &q[i].first);
			q[i].second = i;
			cnt[i] = 0;
		}
		CDQ(0, m);
		for (int i = 0; i < m; ++i)
		{
			printf("%lld\n", ans);
			int p = pos[q[i].first];
			ans += cnt[i] + pre[p] * 2 - p - q[i].first;
		}
		++tim;
	}
	return 0;
}