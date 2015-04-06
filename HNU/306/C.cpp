#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector<int> G[1001];
int ans[1001];

int dfs(int x)
{
	if (G[x].size() == 0)
	{
		return ans[x] = 1;
	}
	if (!ans[x])
	{
		int maxc = 0;
		int maxi = 0;
		for (int i = 0; i < G[x].size(); ++i)
		{
			int t = dfs(G[x][i]);
			if (t > maxc)
			{
				maxc = t;
				maxi = 1;
			}
			else if (t == maxc)
			{
				maxi++;
			}
		}
		ans[x] = maxc + (maxi > 1);
	}
	return ans[x];
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int K, M, P;
		scanf("%d%d%d", &K, &M, &P);
		for (int i = 1; i <= M; ++i)
		{
			G[i].clear();
		}
		while (P--)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			G[v].push_back(u);
		}
		memset(ans, 0, sizeof(ans));
		int s = 0;
		for (int i = 1; i <= M; ++i)
		{
			dfs(i);
			if (ans[i] > s)
			{
				s = ans[i];
			}
		}
		printf("%d %d\n", K, s);
	}
	return 0;
}
