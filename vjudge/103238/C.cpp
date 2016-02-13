#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int blocks = 140;
struct Query
{
	int l, r, id;
	bool operator < (const Query& rhs) const
	{
		return l / blocks < rhs.l / blocks || (l / blocks == rhs.l / blocks && r < rhs.r);
	}
};

const int maxn = 2e4;
int a[maxn + 1];
int phi[maxn + 1];
vector<int> fac[maxn + 1];
int f[maxn + 1];
Query q[maxn];
int ans[maxn];
int cur;

void add(int x)
{
	for (int i = 0; i < fac[x].size(); ++i)
		cur += phi[fac[x][i]] * f[fac[x][i]]++;
}

void sub(int x)
{
	for (int i = 0; i < fac[x].size(); ++i)
		cur -= phi[fac[x][i]] * --f[fac[x][i]];
}

int main()
{
	phi[1] = 1;
	for (int i = 2; i <= maxn; ++i) if (!phi[i])
		for (int j = i; j <= maxn; j += i)
		{
			if (!phi[j]) phi[j] = j;
			phi[j] = phi[j] / i * (i - 1);
		}
	for (int i = 1; i <= maxn; ++i)
		for (int j = 1; i * j <= maxn; ++j)
			fac[i * j].push_back(i);
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
			scanf("%d", &a[i]);
		int Q;
		scanf("%d", &Q);
		for (int i = 0; i < Q; ++i)
		{
			scanf("%d %d", &q[i].l, &q[i].r);
			q[i].id = i;
		}
		sort(q, q + Q);
		int l = 1, r = 1;
		cur = 0;
		for (int i = 1; i <= n; ++i)
			f[i] = 0;
		for (int i = 0; i < Q; ++i)
		{
			while (l < q[i].l) sub(a[l++]);
			while (l > q[i].l) add(a[--l]);
			while (r < q[i].r + 1) add(a[r++]);
			while (r > q[i].r + 1) sub(a[--r]);
			ans[q[i].id] = cur;
		}
		printf("Case #%d:\n", kase);
		for (int i = 0; i < Q; ++i)
			printf("%d\n", ans[i]);
	}
	return 0;
}