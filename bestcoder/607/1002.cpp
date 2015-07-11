#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector<int> G[1000];
bool t[1000][1000];

int main()
{
	int n, m;
	while (scanf("%d %d", &n, &m) == 2)
	{
		for (int i = 0; i < n; ++i)
		{
			G[i].clear();
			scanf("%*d %*d");
		}
		memset(t, 0, sizeof t);
		for (int i = 0; i < m; ++i)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			u--;
			v--;
			G[u].push_back(v);
			G[v].push_back(u);
			t[u][v] = true;
			t[v][u] = true;
		}
		int three = 0;
		int four = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < G[i].size(); ++j)
			{
				for (int k = 0; k < G[i].size(); ++k)
				{
					if (G[i][j] != G[i][k] && t[G[i][j]][G[i][k]])
					{
						three++;
						for (int c = 0; c < G[i].size(); ++c)
						{
							if (G[i][c] != G[i][j] && G[i][c] != G[i][k] && t[i][G[i][c]] && t[G[i][j]][G[i][c]] && t[G[i][k]][G[i][c]])
							{
								four++;
							}
						}
					}
				}
			}
		}
		if (four)
		{
			printf("4 %d\n", four / 24);
		}
		else if (three)
		{
			printf("3 %d\n", three / 6);
		}
		else if (m)
		{
			printf("2 %d\n", m);
		}
		else
		{
			printf("1 %d\n", n);
		}
	}
	return 0;
}
