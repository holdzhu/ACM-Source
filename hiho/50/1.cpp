#include <cstdio>
#include <cstring>

int N;
int G[1001][1001];

void dfs(int x)
{
	for (int i = 1; i <= N; ++i)
	{
		while (G[x][i])
		{
			G[x][i]--;
			G[i][x]--;
			dfs(i);
			printf("%d ", i);
		}
	}
}

int main()
{
	int M;
	scanf("%d %d", &N, &M);
	memset(G, 0, sizeof G);
	while (M--)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		G[u][v]++;
		G[v][u]++;
	}
	int start = 1;
	for (int i = 1; i <= N; ++i)
	{
		int cnt = 0;
		for (int j = 1; j <= N; ++j)
		{
			cnt += G[i][j];
		}
		if (cnt & 1)
		{
			start = i;
			break;
		}
	}
	dfs(start);
	printf("%d\n", start);
	return 0;
}
