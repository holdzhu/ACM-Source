#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

struct Node
{
	int v;
	int p;
};

int V, N, E;
vector<int> G[7];

Node queue[2][100];
int p[2];

int main()
{
	while (scanf("%d", &V) == 1 && V != 0)
	{
		scanf("%d %d", &N, &E);
		for (int i = 0; i < 7; ++i)
		{
			G[i].clear();
		}
		for (int i = 0; i < E; ++i)
		{
			char s[3];
			scanf("%s", s);
			int u = s[0] - 'A';
			int v = s[1] - 'A';
			G[u].push_back(v);
			G[v].push_back(u);
		}
		int minans = 10000;
		for (int i = 0; i < 1 << N; ++i)
		{
			int x = i;
			int count = 0;
			bool vis[N][V];
			bool dontmind[N];
			memset(vis, 0, sizeof vis);
			memset(dontmind, 0, sizeof dontmind);
			p[0] = 0;
			for (int j = 0; j < N; ++j)
			{
				if (x & 1)
				{
					queue[0][p[0]++] = (Node){count++, j};
					dontmind[j] = true;
				}
				x >>= 1;
			}
			if (count == V)
			{
				printf("%d\n", i);
				for (int j = 0; j < N; ++j)
				{
					printf("%d ", dontmind[j]);
				}
				printf("\n");
				int cur = 0;
				bool flag;
				int ans = 0;
				while (1)
				{
					flag = true;
					for (int j = 0; j < N; ++j)
					{
						if (!dontmind[j])
						{
							int c = 0;
							for (int k = 0; k < V; ++k)
							{
								if (vis[j][k])
								{
									c++;
								}
							}
							if (c == 0)
							{
								flag = false;
								break;
							}
						}
					}
					if (flag || p[cur] == 0)
					{
						break;
					}
					p[!cur] = 0;
					for (int j = 0; j < p[cur]; ++j)
					{
						int v = queue[cur][j].v;
						int q = queue[cur][j].p;
						for (vector<int>::iterator k = G[q].begin(); k != G[q].end(); ++k)
						{
							if (!vis[*k][v])
							{
								vis[*k][v] = true;
								queue[!cur][p[!cur]++] = (Node) {v, *k};
							}
						}
					}
					ans++;
					cur = !cur;
				}
				if (flag)
				{
					minans = min(ans, minans);
				}
			}
		}
		if (minans == 10000)
		{
			printf("NEVER\n");
		}
		else
		{
			printf("%d\n", minans);
		}
	}
	return 0;
}
