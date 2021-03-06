#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const long long inf = 1e18;

vector<int> G[1001];
vector<int> W[1001];
bool inq[1001];
vector<int> G2[1001];
bool vis[1001];

long long dis[1001][1001];
long long dis2[1001];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int x, y;
	scanf("%d %d", &x, &y);
	for (int i = 0; i < m; ++i)
	{
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		G[u].push_back(v);
		G[v].push_back(u);
		W[u].push_back(w);
		W[v].push_back(w);
	}
	for (int i = 1; i <= n; ++i)
	{
		int t, c;
		scanf("%d %d", &t, &c);
		for (int j = 1; j <= n; ++j)
			dis[i][j] = t + 1;
		dis[i][i] = 0;
		queue<int> q;
		q.push(i);
		inq[i] = true;
		while (!q.empty())
		{
			int u = q.front();
			q.pop();
			inq[u] = false;
			for (int j = 0; j < G[u].size(); ++j)
			{
				int v = G[u][j];
				int w = W[u][j];
				if (dis[i][v] > dis[i][u] + w)
				{
					dis[i][v] = dis[i][u] + w;
					if (!inq[v])
						inq[v] = true, q.push(v);
				}
			}
		}
		for (int j = 1; j <= n; ++j)
			dis[i][j] = dis[i][j] <= t ? c : inf;
	}
	for (int i = 1; i <= n; ++i)
		dis2[i] = inf;
	dis2[x] = 0;
	for (int i = 0; i < n; ++i)
	{
		int idx = 0;
		for (int j = 1; j <= n; ++j)
			if (!vis[j] && (!idx || dis2[idx] > dis2[j]))
				idx = j;
		vis[idx] = true;
		for (int j = 1; j <= n; ++j)
			if (dis2[j] > dis2[idx] + dis[idx][j])
				dis2[j] = dis2[idx] + dis[idx][j];
	}
	printf("%I64d\n", dis2[y] < inf ? dis2[y] : -1);
	return 0;
}
