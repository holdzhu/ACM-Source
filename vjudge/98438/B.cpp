#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

const int maxn = 3e5;
int lazy[maxn << 2];
int cnt[maxn << 2][11];
int leaf[maxn << 2];
int d[maxn << 1];
int k;

void push_up(int rt)
{
	for (int i = 0; i <= k; ++i)
		cnt[rt][i] = 0;
	if (leaf[rt])
		cnt[rt][min(lazy[rt], k)] += leaf[rt];
	else
		for (int i = max(0, -lazy[rt]); i <= k; ++i)
			cnt[rt][min(lazy[rt] + i, k)] += cnt[rt << 1][i] + cnt[rt << 1 | 1][i];
}

void build(int rt, int L, int R)
{
	for (int i = 1; i <= k; ++i)
		cnt[rt][i] = 0;
	cnt[rt][0] = d[R + 1] - d[L];
	lazy[rt] = 0;
	if (L < R)
	{
		leaf[rt] = 0;
		int M = (L + R) >> 1;
		build(rt << 1, L, M);
		build(rt << 1 | 1, M + 1, R);
	}
	else
		leaf[rt] = d[R + 1] - d[R];
}

void update(int l, int r, int delta, int rt, int L, int R)
{
	if (l <= L && R <= r)
	{
		lazy[rt] += delta;
		push_up(rt);
		return;
	}
	int M = (L + R) >> 1;
	if (l <= M) update(l, r, delta, rt << 1, L, M);
	if (r > M) update(l, r, delta, rt << 1 | 1, M + 1, R);
	push_up(rt);
}

pair<pair<int, int>, pair<int, int> > line[maxn << 1];

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		int n;
		scanf("%d %d", &n, &k);
		map<int, int> ma;
		for (int i = 0; i < n; ++i)
		{
			int x1, y1, x2, y2;
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			line[i << 1] = make_pair(make_pair(x1, 1), make_pair(y1, y2 + 1));
			line[i << 1 | 1] = make_pair(make_pair(x2 + 1, -1), make_pair(y1, y2 + 1));
			ma[y1] = ma[y2 + 1] = 0;
		}
		int m = 0;
		for (auto &p : ma)
		{
			d[m] = p.first;
			p.second = m++;
		}
		build(1, 0, m - 2);
		sort(line, line + n * 2);
		int last = 0;
		long long ans = 0;
		for (int i = 0; i < n * 2; ++i)
		{
			int l = ma[line[i].second.first];
			int r = ma[line[i].second.second] - 1;
			ans += 1ll * cnt[1][k] * (line[i].first.first - last);
			update(l, r, line[i].first.second, 1, 0, m - 2);
			last = line[i].first.first;
		}
		printf("Case %d: %lld\n", kase, ans);
	}
	return 0;
}
