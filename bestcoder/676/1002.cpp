#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int mod = 1e9 + 7;

const int INF = 1e9;

int a[15];
int dis[1 << 17];
bool vis[1 << 17];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		int ans = 0;
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		for (int i = 0; i < (1 << 17); ++i)
			dis[i] = INF, vis[i] = false;
		dis[0] = 0;
		priority_queue<pair<int, int> > pq;
		pq.push(make_pair(0, 0));
		while (!pq.empty())
		{
			int u = pq.top().second;
			pq.pop();
			if (vis[u])
				continue;
			vis[u] = true;
			for (int i = 0; i < 17; ++i)
			{
				int v = u ^ (1 << i);
				if (dis[v] > dis[u] + 1)
				{
					dis[v] = dis[u] + 1;
					pq.push(make_pair(-dis[v], v));
				}
			}
			for (int i = 0; i < n; ++i)
			{
				int v = u ^ a[i];
				if (dis[v] > dis[u] + 1)
				{
					dis[v] = dis[u] + 1;
					pq.push(make_pair(-dis[v], v));
				}
			}
		}
		for (int i = 1; i <= m; ++i)
		{
			int s, t;
			scanf("%d %d", &s, &t);
			ans = (ans + i * dis[s ^ t]) % mod;
		}
		printf("%d\n", ans);
	}
	return 0;
}
