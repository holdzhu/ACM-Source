#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int> > v;
vector<int> G1[1000000];
vector<int> G2[1000000];
int p[1000000];
int dis[1000000];
int deg[1000000];

int findset(int x)
{
	return x == p[x] ? x : p[x] = findset(p[x]);
}

void unionset(int u, int v)
{
	int x = findset(u), y = findset(v);
	if (x != y)
		p[x] = y;
}

int idx(int x, int y)
{
	return x * m + y;
}

int main()
{
	scanf("%d %d", &n, &m);
	v.resize(n);
	for (int i = 0; i < n; ++i)
	{
		v[i].resize(m);
		for (int j = 0; j < m; ++j)
			scanf("%d", &v[i][j]);
	}
	for (int i = 0; i < n * m; ++i)
		p[i] = i;
	for (int i = 0; i < n; ++i)
	{
		vector<pair<int, int> > t(m);
		for (int j = 0; j < m; ++j)
			t[j] = {v[i][j], j};
		sort(t.begin(), t.end());
		for (int j = 1; j < m; ++j)
		{
			if (t[j].first == t[j - 1].first)
				unionset(idx(i, t[j - 1].second), idx(i, t[j].second));
			else
				G1[idx(i, t[j - 1].second)].push_back(idx(i, t[j].second));
		}
	}
	for (int i = 0; i < m; ++i)
	{
		vector<pair<int, int> > t(n);
		for (int j = 0; j < n; ++j)
			t[j] = {v[j][i], j};
		sort(t.begin(), t.end());
		for (int j = 1; j < n; ++j)
		{
			if (t[j].first == t[j - 1].first)
				unionset(idx(t[j - 1].second, i), idx(t[j].second, i));
			else
				G1[idx(t[j - 1].second, i)].push_back(idx(t[j].second, i));
		}
	}
	for (int u = 0; u < n * m; ++u)
		for (int v: G1[u])
		{
			G2[findset(u)].push_back(findset(v));
			deg[findset(v)]++;
		}
	queue<int> q;
	for (int i = 0; i < n * m; ++i)
		if (findset(i) == i && deg[i] == 0)
		{
			q.push(i);
			dis[i] = 1;
		}
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int v: G2[u])
		{
			dis[v] = max(dis[v], dis[u] + 1);
			if (--deg[v] == 0)
				q.push(v);
		}
	}
	for (int i = 0; i < n; ++i, puts(""))
		for (int j = 0; j < m; ++j)
			printf("%d ", dis[findset(idx(i, j))]);
	return 0;
}
