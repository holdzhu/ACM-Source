#include <cstdio>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

bool inq[10000];
vector<int> G[10000];
int a[100000];
int x[100000];
int y[100000];
int c[10000];

int main()
{
	freopen("dwarf.in", "r", stdin);
	freopen("dwarf.out", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%d", &c[i]);
	queue<int> q;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d %d", &a[i], &x[i], &y[i]);
		a[i]--;
		x[i]--;
		y[i]--;
		G[x[i]].push_back(i);
		G[y[i]].push_back(i);
		if (c[x[i]] + c[y[i]] < c[a[i]])
		{
			c[a[i]] = c[x[i]] + c[y[i]];
			if (!inq[a[i]])
			{
				inq[a[i]] = true;
				q.push(a[i]);
			}
		}
	}
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		inq[u] = false;
		for (int i: G[u])
		{
			if (c[x[i]] + c[y[i]] < c[a[i]])
			{
				c[a[i]] = c[x[i]] + c[y[i]];
				if (!inq[a[i]])
				{
					inq[a[i]] = true;
					q.push(a[i]);
				}
			}
		}
	}
	printf("%d\n", c[0]);
	return 0;
}
