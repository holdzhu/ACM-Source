#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

const int maxn = 1e6;

pair<int, int> Q[maxn];
int v[maxn];
int tree[maxn + 1];
int m = 0;
int mx = 1;

inline void update(int x, int delta)
{
	for (++x; x <= m; x += x & -x)
		tree[x] += delta;
}

inline int query(int k)
{
	int sum = 0, ret = 0;
	for (int i = mx - 1; i >= 0; --i)
		if (sum + tree[ret + (1 << i)] < k)
			sum += tree[ret += 1 << i];
	return ret;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int a, b = 0;
		scanf("%d", &a);
		if (a == 1)
		{
			scanf("%d", &b);
			v[m++] = b;
		}
		Q[i] = {a, b};
	}
	sort(v, v + m);
	m = unique(v, v + m) - v;
	while (1 << mx <= m)
		++mx;
	queue<int> q;
	for (int i = 0; i < n; ++i)
	{
		if (Q[i].first == 1)
			update(Q[i].second = lower_bound(v, v + m, Q[i].second) - v, 1),
				q.push(Q[i].second);
		else if (Q[i].first == 2)
			update(q.front(), -1), q.pop();
		else
			printf("%d\n", v[query(q.size() / 2 + 1)]);
	}
	return 0;
}
