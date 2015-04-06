#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int v[100];
vector<int> G[100];
int dp[100][100];
int n, M;

inline int max(int a, int b)
{
	return a > b ? a : b;
}

void dfs(int x, int p)
{
	int size = G[x].size();
	if (p != -1)
	{
		size--;
	}
	dp[x][1] = v[x];
	if (size == 0)
	{
		return;
	}
	for (int i = 0; i < G[x].size(); ++i)
	{
		int u = G[x][i];
		if (u == p)
		{
			continue;
		}
		dfs(u, x);
		for (int m = M; m >= 2; --m)
		{
			for (int j = 1; j < m; ++j)
			{
				dp[x][m] = max(dp[x][m], dp[x][m - j] + dp[u][j]);
			}
		}
	}
}

int main()
{
	scanf("%d %d", &n, &M);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &v[i]);
	}
	for (int i = 0; i < n - 1; ++i)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		u--;
		v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	memset(dp, 0, sizeof(dp));
	dfs(0, -1);
	printf("%d\n", dp[0][M]);
	return 0;
}
