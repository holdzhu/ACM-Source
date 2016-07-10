#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
long long tree[100001];

inline int lowbit(int x)
{
	return x & (-x);
}

void update(int x, long long val)
{
	while (x <= n)
	{
		tree[x] = max(tree[x], val);
		x += lowbit(x);
	}
}

long long query(int x)
{
	long long ret = 0;
	while (x)
	{
		ret = max(ret, tree[x]);
		x -= lowbit(x);
	}
	return ret;
}

pair<long long, int> v[100000];
long long dp[100001];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int r, h;
		scanf("%d %d", &r, &h);
		v[i] = {1ll * r * r * h, i + 1};
	}
	sort(v, v + n);
	long long ans = 0;
	for (int i = 0; i < n;)
	{
		int j;
		for (j = i; j < n && v[i].first == v[j].first; ++j)
			;
		for (int k = i; k < j; ++k)
		{
			dp[v[k].second] = query(v[k].second - 1) + v[k].first;
			ans = max(ans, dp[v[k].second]);
		}
		for (int k = i; k < j; ++k)
			update(v[k].second, dp[v[k].second]);
		i = j;
	}
	printf("%.10f\n", ans * acos(-1));
	return 0;
}
