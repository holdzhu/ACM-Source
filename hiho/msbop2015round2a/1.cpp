#include <cstdio>
#include <vector>
#include <set>

using namespace std;

vector<int> G[100000];
int color[100000];

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 0; kase < T; ++kase)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			G[i].clear();
			color[i] = 0;
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
		int q;
		scanf("%d", &q);
		int ans = 1;
		printf("Case #%d: \n", kase + 1);
		for (int i = 0; i < q; ++i)
		{
			int type;
			scanf("%d", &type);
			if (type == 1)
			{
				printf("%d\n", ans);
			}
			else
			{
				int x, y;
				scanf("%d %d", &x, &y);
				x--;
				int first = 0;
				int last = 0;
				for (int j = 0; j < G[x].size(); ++j)
				{
					if (color[G[x][j]] == color[x])
					{
						first++;
					}
					if (color[G[x][j]] == y)
					{
						last++;
					}
				}
				ans -= last;
				ans += first;
				color[x] = y;
			}
		}
	}
	return 0;
}
