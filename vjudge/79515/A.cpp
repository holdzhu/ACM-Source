#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

struct Edge
{
	int u, v;
};

Edge edge[59998];
vector<int> G[30000];
long long dpnum[59998];
long long dpval[59998];
long long sum[59998];
int times[30000];
int total[30000];

void dfs(int x)
{
	if (dpnum[x] == -1)
	{
		dpnum[x] = 1;
		dpval[x] = 0;
		for (int i = 0; i < G[edge[x].v].size(); ++i)
		{
			int y = G[edge[x].v][i];
			if (y == (x ^ 1))
			{
				continue;
			}
			dfs(y);
			dpnum[x] += dpnum[y];
			dpval[x] += dpval[y] + dpnum[y];
		}
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		int N, C;
		scanf("%d %d", &N, &C);
		for (int i = 0; i < N - 1; ++i)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			u--;
			v--;
			edge[i << 1] = (Edge){u, v};
			edge[i << 1 ^ 1] = (Edge){v, u};
			G[u].push_back(i << 1);
			G[v].push_back(i << 1 ^ 1);
		}
		memset(times, 0, sizeof times);
		memset(total, 0, sizeof total);
		while (C--)
		{
			int X, K;
			scanf("%d %d", &X, &K);
			X--;
			times[X]++;
			total[X] += K;
		}
		memset(dpnum, -1, sizeof dpnum);
		for (int i = 0; i < N * 2 - 2; ++i)
		{
			dfs(i);
		}
	}
	return 0;
}
