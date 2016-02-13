#pragma comment(linker, "/STACK:102400000,102400000")
#include <cstdio>
#include <vector>

using namespace std;

int n;
int tree[100001];
vector<int> G1[100001];
vector<int> G[100001];
int tim;
int in[100001];
int out[100001];
long long ans;

void dfs1(int u)
{
	in[u] = ++tim;
	for (int i = 0; i < G1[u].size(); ++i)
		dfs1(G1[u][i]);
	out[u] = tim;
}

inline int lowbit(int x)
{
	return x & (-x);
}

void update(int x)
{
	while (x <= n)
	{
		tree[x]++;
		x += lowbit(x);
	}
}

int query(int x)
{
	int ret = 0;
	while (x)
	{
		ret += tree[x];
		x -= lowbit(x);
	}
	return ret;
}

void dfs(int u)
{
	update(in[u]);
	++tim;
	int cnt = query(out[u]) - query(in[u]);
	for (int i = 0; i < G[u].size(); ++i)
		dfs(G[u][i]);
	cnt = (query(out[u]) - query(in[u])) - cnt;
	ans += 1ll * cnt * (cnt - 1) / 2;
}

int deg[100001];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		G1[u].push_back(v);
		deg[v]++;
	}
	for (int i = 1; i <= n; ++i)
		if (deg[i] == 0)
			dfs1(i);
	for (int i = 1; i <= n; ++i)
		deg[i] = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		deg[v]++;
	}
	tim = 0;
	for (int i = 1; i <= n; ++i)
		if (deg[i] == 0)
			dfs(i);
	printf("%lld\n", ans);
	return 0;
}
