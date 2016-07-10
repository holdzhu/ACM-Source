#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> G[100001];
int dep[100001];
bool vis[100001];
int deg[100001];
vector<int> rts;
int tar[100001];
int tim[100001];

void dfs(int u)
{
	for (int v : G[u])
	{
		dep[v] = dep[u] + 1;
		dfs(v);
	}
}

bool check(int u, pair<int, int> p = {1e9, 1e9})
{
	if (tim[u] != -1)
		p = min(p, make_pair(tim[u], u));
	if (tar[u] != p.second)
		return false;
	for (int v: G[u])
		if (!check(v, p))
			return false;
	return true;
}

bool check()
{
	for (int rt: rts)
		if (!check(rt))
			return false;
	return true;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		++deg[v];
	}
	for (int i = 1; i <= n; ++i)
		if (deg[i] == 0)
			rts.push_back(i);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &tar[i]), tim[i] = -1;
	for (int rt: rts)
		dfs(rt);
	vector<pair<int, int> > v;
	for (int i = 1; i <= n; ++i)
		if (!vis[tar[i]])
		{
			vis[tar[i]] = true;
			v.emplace_back(-dep[tar[i]], tar[i]);
		}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); ++i)
		tim[v[i].second] = i;
	if (check())
	{
		printf("%d\n", v.size());
		for (int i = 0; i < v.size(); ++i)
			printf("%d\n", v[i].second);
	}
	else
		puts("-1");
	return 0;
}
