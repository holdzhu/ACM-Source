#include <cstdio>
#include <vector>

using namespace std;

vector<int> G[100001];
int val[200000];
bool in[200000];
int cnt[1 << 17];
int tim;

void dfs(int u, int fa)
{
	in[tim] = 1;
	val[tim++] = u;
	for (int v: G[u])
	{
		if (v == fa)
			continue;
		dfs(v, u);
	}
	val[tim++] = u;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(2, 0);
	long long ans = 0;
	int xr = 0;
	for (int i = 0; i < n + n; ++i)
	{
		if (in[i])
			cnt[xr]++;
		xr ^= val[i];
		if (in[i])
			ans += cnt[xr];
	}
	printf("%lld\n", ans);
	return 0;
}
