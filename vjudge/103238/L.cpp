#include <cstdio>
#include <vector>

using namespace std;

vector<int> G[105];

int dfs(int u, int fa)
{
	int ret = 0;
	for (int i = 0; i < G[u].size(); ++i)
	{
		int v = G[u][i];
		if (v == fa)
			continue;
		ret ^= dfs(v, u) + 1;
	}
	return ret;
}

int main()
{
	int N;
	while (scanf("%d", &N) == 1)
	{
		int ans = 0;
		bool flag = true;
		for (int i = 0; i < N; ++i)
		{
			int m;
			scanf("%d", &m);
			for (int j = 1; j <= m; ++j)
				G[j].clear();
			while (--m)
			{
				int u, v;
				scanf("%d %d", &u, &v);
				G[u].push_back(v);
				G[v].push_back(u);
			}
			int t = dfs(1, 0);
			if (t > 1)
				flag = false;
			ans ^= dfs(1, 0);
		}
		puts((flag && !ans) || (!flag && ans) ? "PP" : "QQ");
	}
	return 0;
}
