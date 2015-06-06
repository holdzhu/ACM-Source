#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> G[201];
long long dp[201][201];
int b[201] = {0};

void dfs(int x)
{
	dp[x][1] = b[x];
	for (int i = 0; i < G[x].size(); ++i)
	{
		dfs(G[x][i]);
		for (int j = M; j >= 1; --j)
		{
			for (int k = j - 1; k >= 1; --k)
			{
				dp[x][j] = max(dp[x][j], dp[x][k] + dp[G[x][i]][j - k]);
			}
		}
	}
}

int main()
{
	int N;
	while (scanf("%d %d", &N, &M) == 2 && N && M)
	{
		M++;
		for (int i = 0; i <= N; ++i)
		{
			G[i].clear();
		}
		memset(dp, 0, sizeof dp);
		for (int i = 1; i <= N; ++i)
		{
			int a;
			scanf("%d %d", &a, &b[i]);
			G[a].push_back(i);
		}
		dfs(0);
		printf("%lld\n", dp[0][M]);
	}
	return 0;
}
