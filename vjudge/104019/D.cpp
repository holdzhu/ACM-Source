#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int> > G[10000];
vector<int> R[10000];
int deg[10000];
int deginv[10000];
int sum[10000];
double E[10000];
double P[10000];

int main()
{
	int N, M;
	while (scanf("%d %d", &N, &M) == 2 && N)
	{
		for (int i = 0; i < N; ++i)
			G[i].clear(), R[i].clear(), deg[i] = 0, sum[i] = 0, E[i] = 0, P[i] = 0;
		while (M--)
		{
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			G[u].push_back({v, w});
			R[v].push_back(u);
			deg[v]++;
			deginv[u]++;
			sum[u] += w;
		}
		queue<int> q;
		for (int i = 0; i < N; ++i)
			if (deginv[i] == 0)
				q.push(i);
		while (!q.empty())
		{
			int u = q.front();
			q.pop();
			for (pair<int, int> v: G[u])
				E[u] += 1.0 * v.second / sum[u] * (E[v.first] + 1);
			for (int v: R[u])
				if (--deginv[v] == 0)
					q.push(v);
		}
		P[0] = 1;
		for (int i = 0; i < N; ++i)
			if (deg[i] == 0)
				q.push(i);
		double ans = E[0];
		while (!q.empty())
		{
			int u = q.front();
			q.pop();
			for (pair<int, int> v: G[u])
			{
				if (--deg[v.first] == 0)
					q.push(v.first);
				if (G[u].size() == 1)
					break;
				double p = 1.0 * v.second / sum[u];
				P[v.first] += p * P[u];
				ans = max(ans, E[0] + P[u] * p * ((E[u] - p * E[v.first] - 1) / (1 - p) - E[v.first]));
			}
		}
		printf("%.8f\n", ans);
	}
	return 0;
}