#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<pair<int, int> > G[100001];
bool vis[100001];
long long dis[100001];
long long loop = 0;

void dfs(int u)
{
	vis[u] = true;
	for (auto &p: G[u])
	{
		int v = p.first;
		int w = p.second;
		if (vis[v])
		{
			if (dis[v] - dis[u] != w)
				loop = dis[v] - dis[u] - w;
		}
		else
		{
			dis[v] = dis[u] + w;
			dfs(v);
		}
	}
}

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		G[u].emplace_back(v, w);
		G[v].emplace_back(u, -w);
	}
	dfs(1);
	int Q;
	scanf("%d", &Q);
	for (int i = 0; i < Q; ++i)
	{
		int S, E, M;
		scanf("%d %d %d", &S, &E, &M);
		long long ans = dis[E] - dis[S];
		ans = (ans % M + M) % M;
		if (loop % M)
		{
			long long delta = abs(__gcd(loop, (long long)M));
			int t = (M - 1 - ans) / delta;
			ans += t * delta;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
