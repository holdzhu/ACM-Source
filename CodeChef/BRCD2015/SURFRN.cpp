#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

struct Node
{
	int step, p;
};

vector<int> G[101];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N, A, B;
		scanf("%d%d%d", &N, &A, &B);
		for (int i = 1; i <= N; ++i)
		{
			G[i].clear();
		}
		for (int i = 0; i < N - 1; ++i)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);	
		}
		bool vis[N + 1];
		memset(vis, 0, sizeof(vis));
		queue<Node> q;
		q.push((Node) {0, A});
		vis[A] = true;
		while (!q.empty())
		{
			Node p = q.front();
			q.pop();
			int u = p.p;
			if (u == B)
			{
				printf("%d\n", p.step);
				break;
			}
			for (int i = 0; i < G[u].size(); ++i)
			{
				int v = G[u][i];
				if (!vis[v])
				{
					q.push((Node) {p.step + 1, v});
					vis[v] = true;
				}
			}
		}
	}
	return 0;
}
