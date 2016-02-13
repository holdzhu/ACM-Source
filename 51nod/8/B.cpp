#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

int a[100010];
map<int, int> id;
int val[200010];
int cmd[200010];
int v[200010];
int m = 0;
long long treenum[200010];
long long treesum[200010];
int cnt[200010];

int lowbit(int x)
{
	return x & (-x);
}

void update(long long *tree, int idx, int val)
{
	while (idx <= m)
	{
		tree[idx] += val;
		idx += lowbit(idx);
	}
}

long long query(long long *tree, int idx)
{
	long long ret = 0;
	while (idx)
	{
		ret += tree[idx];
		idx -= lowbit(idx);
	}
	return ret;
}

int main()
{
	int n, q;
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
		id[a[i]] = 0;
	}
	for (int i = 0; i < q; ++i)
	{
		scanf("%d", &cmd[i]);
		if (cmd[i] < 3)
		{
			scanf("%d", &v[i]);
			id[v[i]] = 0;
		}
	}
	for (auto &p : id)
	{
		p.second = ++m;
		val[m] = p.first;
	}
	long long ans = 0;
	long long tsum = 0;
	long long tnum = 0;
	sort(a, a + n);
	for (int i = 0; i < n; ++i)
	{
		ans += tnum * a[i] - tsum;
		tsum += a[i];
		tnum++;
		int t = id[a[i]];
		cnt[t]++;
		update(treesum, t, a[i]);
		update(treenum, t, 1);
	}
	for (int i = 0; i < q; ++i)
	{
		if (cmd[i] == 3)
		{
			printf("%I64d\n", ans);
			continue;
		}
		int t = id[v[i]];
		if (cmd[i] == 2 && cnt[t] == 0)
		{
			printf("-1\n");
			continue;
		}
		long long sum = query(treesum, t - 1);
		long long num = query(treenum, t - 1);
		long long delta = num * v[i] - sum + (tsum - sum - cnt[t] * v[i]) - (tnum - num - cnt[t]) * v[i];
		if (cmd[i] == 1)
		{
			ans += delta;
			cnt[t]++;
			update(treesum, t, v[i]);
			update(treenum, t, 1);
			tsum += v[i];
			tnum++;
		}
		else
		{
			ans -= delta;
			cnt[t]--;
			update(treesum, t, -v[i]);
			update(treenum, t, -1);
			tsum -= v[i];
			tnum--;
		}
	}
	return 0;
}
