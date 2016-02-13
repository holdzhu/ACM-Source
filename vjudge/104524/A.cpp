#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector<int> G[100000];
vector<int> R[100000];

bool vis1[100000];
bool vis2[100000];

int f[100000];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &f[i]);
	}
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		u--, v--;
		G[u].push_back(v);
		R[v].push_back(u);
	}
	queue<int> q1, q2;
	for (int i = 0; i < n; ++i)
	{
		if (f[i] == 1)
		{
			vis1[i] = true;
			q1.push(i);
		}
		else if (f[i] == 2)
		{
			vis2[i] = true;
			q2.push(i);
		}
	}
	while (!q1.empty())
	{
		int u = q1.front();
		q1.pop();
		for (int i = 0; i < G[u].size(); ++i)
		{
			int v = G[u][i];
			if (!vis1[v])
			{
				vis1[v] = true;
				q1.push(v);
			}
		}
	}
	while (!q2.empty())
	{
		int u = q2.front();
		q2.pop();
		if (f[u] != 1) for (int i = 0; i < R[u].size(); ++i)
		{
			int v = R[u][i];
			if (!vis2[v])
			{
				vis2[v] = true;
				q2.push(v);
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		printf("%d\n", (int)(vis1[i] && vis2[i]));
	}
	return 0;
}
