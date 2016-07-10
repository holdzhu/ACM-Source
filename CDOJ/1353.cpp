#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int mod = 1e9 + 9;

int a[100000];
vector<int> vals;
int tree[100001];

void update(int x, int val)
{
	for (; x <= vals.size(); x += x & -x)
	{
		tree[x] += val;
		if (tree[x] >= mod)
			tree[x] -= mod;
	}
}

int query(int x)
{
	int ret = 0;
	for (; x; x -= x & -x)
	{
		ret += tree[x];
		if (ret >= mod)
			ret -= mod;
	}
	return ret;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]), vals.push_back(a[i]);
	sort(vals.begin(), vals.end());
	vals.erase(unique(vals.begin(), vals.end()), vals.end());
	for (int i = 0; i < n; ++i)
	{
		int x = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin() + 1;
		int l = lower_bound(vals.begin(), vals.end(), a[i] - m) - vals.begin();
		int r = upper_bound(vals.begin(), vals.end(), a[i] + m) - vals.begin();
		update(x, (query(r) + mod - query(l) + 1) % mod);
	}
	printf("%d\n", query(vals.size()) - n);
	return 0;
}
