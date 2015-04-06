#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct Node
{
	int pos, step;
};

vector<pair<int, int> > V;
vector<int> G[1000];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N, S, F;
		double L1, L2;
		scanf("%d %d %d %lf %lf", &N, &S, &F, &L1, &L2);
		S--;
		F--;
		V.clear();
		for (int i = 0; i < N; ++i)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			V.push_back(make_pair(x, y));
			G[i].clear();
		}
		for (int i = 0; i < N; ++i)
		{
			for (int j = i + 1; j < N; ++j)
			{
				long long t = ((long long)V[i].first - V[j].first) * (V[i].first - V[j].first) + ((long long)V[i].second - V[j].second) * (V[i].second - V[j].second);
				if (t <= (L1 + L2) * (L1 + L2))
				{
					G[i].push_back(j);
					G[j].push_back(i);
				}
			}
		}
		queue<Node> q;
		q.push((Node) {S, 0});
		bool finish = false;
		bool vis[N];
		memset(vis, 0, sizeof(vis));
		while (!q.empty())
		{
			Node node = q.front();
			q.pop();
			int & u = node.pos;
			if (vis[u])
			{
				continue;
			}
			vis[u] = true;
			if (u == F)
			{
				printf("%d\n", node.step);
				finish = true;
				break;
			}
			for (int i = 0; i < G[u].size(); ++i)
			{
				if (!vis[G[u][i]])
				{
					q.push((Node) {G[u][i], node.step + 1});
				}
			}
		}
		if (!finish)
		{
			printf("Impossible\n");
		}
	}
	return 0;
}
