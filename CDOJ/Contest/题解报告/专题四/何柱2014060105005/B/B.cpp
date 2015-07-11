#include <cstdio>
#include <cstring>
#include <climits>
#include <vector>

using namespace std;

struct Road
{
	int Xor;
	int w;
};

const int mod = 1000000009;

vector<int> G[2000];
Road road[2000];
int dis[2000];
long long discount[2000];
bool isZero[2000];
bool vis[2000];

struct cmp
{
	bool operator () (const int& a, const int& b) const
	{
		return dis[a] > dis[b];
	}
};

int main()
{
	int n, m;
	memset(isZero, false, sizeof isZero);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		scanf("%d %d %d", &u, &v, &road[i].w);
		u--;
		v--;
		road[i].Xor = u ^ v;
		G[u].push_back(i);
		G[v].push_back(i);
		if (road[i].w == 0)
		{
			isZero[u] = isZero[v] = true;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		dis[i] = INT_MAX;
		discount[i] = -1;
	}
	dis[0] = 0;
	discount[0] = 1;
	memset(vis, false, sizeof vis);
	for (int i = 0; i < n; ++i)
	{
		int u = -1;
		int near = INT_MAX;
		for (int j = 0; j < n; ++j)
		{
			if (!vis[j] && dis[j] < near)
			{
				near = dis[j];
				u = j;
			}
		}
		if (u == -1)
		{
			break;
		}
		vis[u] = true;
		for (int j = 0; j < G[u].size(); ++j)
		{
			int v = road[G[u][j]].Xor ^ u;
			if (dis[v] == dis[u] + road[G[u][j]].w)
			{
				discount[v] += discount[u];
				discount[v] %= mod;
			}
			else if (dis[v] > dis[u] + road[G[u][j]].w)
			{
				dis[v] = dis[u] + road[G[u][j]].w;
				discount[v] = discount[u];
			}
		}
	}
	int rdis = dis[n - 1];
	long long rdiscount = discount[n - 1];
	for (int i = 0; i < n; ++i)
	{
		dis[i] = INT_MAX;
		discount[i] = -1;
	}
	dis[0] = 0;
	discount[0] = 1;
	memset(vis, false, sizeof vis);
	for (int i = 0; i < n; ++i)
	{
		int u = -1;
		int near = INT_MAX;
		for (int j = 0; j < n; ++j)
		{
			if (!vis[j] && dis[j] < near)
			{
				near = dis[j];
				u = j;
			}
		}
		if (u == -1)
		{
			break;
		}
		vis[u] = true;
		if (isZero[u])
		{
			continue;
		}
		for (int j = 0; j < G[u].size(); ++j)
		{
			int v = road[G[u][j]].Xor ^ u;
			if (dis[v] == dis[u] + road[G[u][j]].w)
			{
				discount[v] += discount[u];
				discount[v] %= mod;
			}
			else if (dis[v] > dis[u] + road[G[u][j]].w)
			{
				dis[v] = dis[u] + road[G[u][j]].w;
				discount[v] = discount[u];
			}
		}
	}
	if (rdiscount == discount[n - 1] && rdis == dis[n - 1])
	{
		printf("%lld\n", rdiscount);
	}
	else
	{
		printf("-1\n");
	}
	return 0;
}
