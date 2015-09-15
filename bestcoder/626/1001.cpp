#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int cnt[1001];
vector<int> G[1001];

void dfs(int u, int fa, int d)
{
	cnt[d]++;
	for (int i = 0; i < G[u].size(); ++i)
	{
		int v = G[u][i];
		if (v == fa)
		{
			continue;
		}
		dfs(v, u, d + 1);
	}
}

int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		memset(cnt, 0, sizeof cnt);
		for (int i = 0; i < n; ++i)
		{
			G[i + 1].clear();
		}
		for (int i = 0; i < n - 1; ++i)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(1, -1, 0);
		int last = -1;
		for (int i = 0; i <= 1000; ++i)
		{
			if (cnt[i] > 1)
			{
				last = i;
				break;
			}
		}
		bool flag = true;
		if (last != -1)
		{
			for (int i = last + 1; i <= 1000; ++i)
			{
				if (cnt[i] != 0)
				{
					flag = false;
					break;
				}
			}
		}
		puts(flag ? "YES" : "NO");
	}
	return 0;
}
