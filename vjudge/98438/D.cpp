#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

const int maxn = 1e5;
pair<pair<int, int>, int> p[maxn];
pair<pair<int, int>, int> tmp[maxn];
map<int, int> id;
int M = 0;
int tree[maxn + 1];
int dp[maxn + 1];
int vis[maxn + 1];
int tim = 0;

inline int lowbit(int x)
{
	return x & (-x);
}

void update(int x, int val)
{
	while (x <= M)
	{
		if (vis[x] < tim)
		{
			tree[x] = 0;
			vis[x] = tim;
		}
		tree[x] = max(tree[x], val);
		x += lowbit(x);
	}
}

int query(int x)
{
	int ret = 0;
	while (x)
	{
		if (vis[x] < tim)
		{
			tree[x] = 0;
			vis[x] = tim;
		}
		ret = max(ret, tree[x]);
		x -= lowbit(x);
	}
	return ret;
}

void solve(int l, int m, int r)
{
	copy(p + l, p + r, tmp + l);
	sort(tmp + l, tmp + m);
	sort(tmp + m, tmp + r);
	for (int i = l, j = m; j < r; ++j)
	{
		while (i < m && tmp[i].first.first < tmp[j].first.first)
		{
			update(tmp[i].first.second, dp[tmp[i].second]);
			i++;
		}
		dp[tmp[j].second] = max(dp[tmp[j].second], query(tmp[j].first.second - 1) + 1);
	}
	tim++;
}

void CDQ(int l, int r)
{
	if (r - l > 1)
	{
		int m = (l + r) >> 1;
		CDQ(l, m);
		solve(l, m, r);
		CDQ(m, r);
	}
	else
	{
		dp[l] = max(dp[l], 1);
	}
}

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d %d", &p[i].first.first, &p[i].first.second);
		id[p[i].first.second] = 0;
		p[i].second = i;
	}
	for (auto &p : id)
	{
		p.second = ++M;
	}
	for (int i = 0; i < N; ++i)
	{
		p[i].first.second = id[p[i].first.second];
	}
	CDQ(0, N);
	int ans = 0;
	for (int i = 0; i < N; ++i)
	{
		ans = max(ans, dp[i]);
	}
	printf("%d\n", ans);
	return 0;
}
