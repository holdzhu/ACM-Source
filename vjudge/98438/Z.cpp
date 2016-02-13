#include <cstdio>
#include <unordered_map>

using namespace std;

const int maxn = 2e5;
unordered_map<int, int> p[maxn + 1], ans[maxn + 1];

int findSet(int x, int c)
{
	return x == p[x][c] ? x : p[x][c] = findSet(p[x][c], c);
}

void unionSet(int x, int y, int c)
{
	if (!p[x].count(c)) p[x][c] = x;
	if (!p[y].count(c)) p[y][c] = y;
	int u = findSet(x, c);
	int v = findSet(y, c);
	p[u][c] = v;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	while (m--)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		unionSet(a, b, c);
	}
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		if (p[u].size() > p[v].size() || (p[u].size() == p[v].size() && u > v))
		{
			swap(u, v);
		}
		if (!ans[u].count(v))
		{
			auto &it = ans[u][v];
			for (auto c : p[u])
			{
				if (p[v].count(c.first) && findSet(u, c.first) == findSet(v, c.first))
				{
					it++;
				}
			}
		}
		printf("%d\n", ans[u][v]);
	}
	return 0;
}
