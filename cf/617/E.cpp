#include <cstdio>
#include <algorithm>

using namespace std;

const int blocks = 300;

struct Query
{
	int l, r, id;
	bool operator < (const Query& rhs) const
	{
		return l / blocks < rhs.l / blocks || (l / blocks == rhs.l / blocks && r < rhs.r);
	}
};

int n, m, k;
Query q[100000];
long long ans[100000];
int s[100001];
int cnt[1 << 20];
long long cur;

void add(int x)
{
	cur += cnt[x ^ k];
	cnt[x]++;
}

void del(int x)
{
	cnt[x]--;
	cur -= cnt[x ^ k];
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &s[i]);
		s[i] ^= s[i - 1];
	}
	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d", &q[i].l, &q[i].r);
		q[i].id = i;
	}
	sort(q, q + m);
	int l = 1, r = 0;
	for (int i = 0; i < m; ++i)
	{
		while (q[i].l - 1 > l) del(s[l++]);
		while (q[i].l - 1 < l) add(s[--l]);
		while (q[i].r > r) add(s[++r]);
		while (q[i].r < r) del(s[r--]);
		ans[q[i].id] = cur;
	}
	for (int i = 0; i < m; ++i)
	{
		printf("%I64d\n", ans[i]);
	}
	return 0;
}
