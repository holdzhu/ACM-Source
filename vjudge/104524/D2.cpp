#include <cstdio>
#include <cassert>
#include <vector>
#include <queue>

using namespace std;

int n, k;
int x[1000], y[1000];

vector<int> G[1000];
bool ans[1000];
int deg[1000];
queue<int> q;

void add(int u)
{
	for (int v: G[u])
		deg[v]--;
	ans[u] = true;
}

void del(int u)
{
	deg[u] = 0;
	for (int v: G[u])
	{
		if (deg[v] == 0 && !ans[v])
			q.push(v);
		deg[v]++;
		deg[u] += !ans[v];
	}
	ans[u] = false;
	if (deg[u])
		q.push(u);
}

bool dfs(int rem)
{
	if (rem < 0)
		return false;
	while (q.size() && (ans[q.front()] || deg[q.front()] == 0))
		q.pop();
	if (q.empty())
		return true;
	int u = q.front();
	if (deg[u] > 1)
	{
		add(u);
		if (dfs(rem - 1))
			return true;
		del(u);
	}
	vector<int> t;
	for (int v: G[u])
		if (!ans[v])
			add(v), t.push_back(v);
	if (dfs(rem - t.size()))
		return true;
	for (int v: t)
		del(v);
	return false;
}

bool check(int dis)
{
	for (int i = 0; i < n; ++i)
		ans[i] = false, G[i].clear();
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			if ((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) > dis)
			{
				G[i].push_back(j);
				G[j].push_back(i);
			}
	for (int i = 0; i < n; ++i)
		if (deg[i] = G[i].size())
			q.push(i);
	return dfs(k);
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d %d", &x[i], &y[i]);
	int l = 0, r = 32000 * 32000 * 2;
	while (l < r)
	{
		int m = (0ll + l + r) >> 1;
		if (check(m))
			r = m;
		else
			l = m + 1;
	}
	check(l);
	for (int i = 0; i < n && k; ++i)
		if (ans[i])
			printf("%d ", i + 1), k--;
	for (int i = 0; i < n && k; ++i)
		if (!ans[i])
			printf("%d ", i + 1), k--;
	puts("");
	return 0;
}
