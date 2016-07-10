#include <algorithm>
#include <cstdio>
#include <map>

using namespace std;

map<pair<int, pair<int, int> >, int> id;
pair<pair<int, int>, int> q[200010];

int n;
int a[200010];
int *p[200010];
int last[200010];
int nxt[200010];
int tree[200010];
int ans[200010];
bool zero[200010];

void update(int x, int val)
{
	for (++x; x <= n; x += x & (-x))
		tree[x] += val;
}

int query(int x)
{
	int ret = 0;
	for (++x; x; x -= x & (-x))
		ret += tree[x];
	return ret;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		id.clear();
		for (int i = 0; i < n + 2; ++i)
			tree[i] = 0;
		for (int i = 0; i < n - 2; ++i)
		{
			if (a[i] <= a[i + 1] && a[i + 1] <= a[i + 2])
				zero[i] = false,
				p[i] = &id[make_pair(a[i], make_pair(a[i + 1], a[i + 2]))];
			else
				zero[i] = true;
		}
		int m = 0;
		for (map<pair<int, pair<int, int> >, int>::iterator it = id.begin();
			 it != id.end(); ++it)
			it->second = m++;
		n -= 2;
		for (int i = 0; i < m; ++i)
			last[i] = n;
		for (int i = n - 1; i >= 0; --i)
		{
			if (zero[i])
				nxt[i] = n;
			else
			{
				nxt[i] = last[*p[i]];
				last[*p[i]] = i;
			}
		}
		for (int i = 0; i < m; ++i)
			update(last[i], 1);
		int Q;
		scanf("%d", &Q);
		for (int i = 0; i < Q; ++i)
		{
			int l, r;
			scanf("%d %d", &l, &r);
			l -= 1;
			r -= 3;
			q[i] = make_pair(make_pair(l, r), i);
		}
		sort(q, q + Q);
		for (int i = 0, j = 0; i < n; ++i)
		{
			while (j < Q && q[j].first.first == i)
			{
				int r = q[j].first.second;
				int id = q[j].second;
				if (r < i)
					ans[id] = 0;
				else
					ans[id] = query(r);
				++j;
			}
			if (!zero[i])
				update(i, -1);
			if (nxt[i] != n)
				update(nxt[i], 1);
		}
		for (int i = 0; i < Q; ++i)
			printf("%d\n", ans[i]);
	}
	return 0;
}
