#include <cstdio>
#include <cstring>

int n;
int col[500];
bool G[500][500];

bool dfs(int u, int v)
{
	for (int i = 0; i < n; ++i)
	{
		if (col[i] >= 0)
		{
			if ((G[u][i] && col[i] == col[u]) || (G[v][i] && col[i] == col[v]))
			{
				return false;
			}
		}
		else if (G[u][i] && G[v][i])
		{
			col[i] = 3 - col[u] - col[v];
			if (!dfs(u, i) || !dfs(v, i))
			{
				return false;
			}
		}
	}
	return true;
}

bool solve()
{
	memset(col, -1, sizeof col);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < n; ++k)
			{
				if (G[i][j] && G[i][k] && G[j][k])
				{
					col[i] = 0;
					col[j] = 1;
					col[k] = 2;
					if (!dfs(i, j) || !dfs(i, k) || !dfs(j, k))
					{
						return false;
					}
					return true;
				}
			}
		}
	}
	return false;
}

int main()
{
	freopen("mayors.in", "r", stdin);
	freopen("mayors.out", "w", stdout);
	int m;
	scanf("%d %d", &n, &m);
	memset(G, false, sizeof G);
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		u--;
		v--;
		G[u][v] = G[v][u] = true;
	}
	if (n == 1)
	{
		puts("Plan OK\nR");
	}
	else if (n == 2)
	{
		puts("Plan OK\nRG");
	}
	else
	{
		if (solve())
		{
			puts("Plan OK");
			for (int i = 0; i < n; ++i)
			{
				putchar("RGB"[col[i]]);
			}
			puts("");
		}
		else
		{
			puts("Plan failed");
		}
	}
	return 0;
}
