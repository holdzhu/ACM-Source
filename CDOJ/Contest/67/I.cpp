#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

vector<int> G[200];
int in[200];
int n, m;
int stk[200];
int pos;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		pos = 0;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; ++i)
		{
			G[i].clear();
		}
		memset(in, 0, sizeof in);
		for (int i = 0; i < m; ++i)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			u--;
			v--;
			G[v].push_back(u);
			in[u]++;
		}
		priority_queue<int> q;
		for (int i = 0; i < n; ++i)
		{
			if (in[i] == 0)
			{
				q.push(i);
			}
		}
		while (!q.empty())
		{
			int p = q.top();
			q.pop();
			stk[p] = n - pos++;
			for (int i = 0; i < G[p].size(); ++i)
			{
				in[G[p][i]]--;
				if (in[G[p][i]] == 0)
				{
					q.push(G[p][i]);
				}
			}
		}
		if (pos == n)
		{
			for (int i = 0; i < n; ++i)
			{
				if (i)
				{
					printf(" ");
				}
				printf("%d", stk[i]);
			}
			printf("\n");
		}
		else
		{
			printf("-1\n");
		}
	}
	return 0;
}
