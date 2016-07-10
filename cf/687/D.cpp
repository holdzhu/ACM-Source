#include <cstdio>
#include <algorithm>

using namespace std;

struct Edge
{
	int u, v, w, id;
	bool operator < (const Edge &rhs) const
	{
		return w < rhs.w;
	}
};

int p[1001];
bool col[1001];

int findset(int x)
{
	if (x == p[x])
		return x;
	int t = findset(p[x]);
	col[x] ^= col[p[x]];
	return p[x] = t;
}

Edge edge[1000 * 999 / 2 + 1];

int main()
{
	int n, m, q;
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 1; i <= m; ++i)
		scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w), edge[i].id = i;
	sort(edge + 1, edge + m + 1);
	while (q--)
	{
		int l, r;
		scanf("%d %d", &l, &r);
		for (int i = 1; i <= n; ++i)
			p[i] = i, col[i] = 0;
		int pos;
		for (pos = m; pos > 0; --pos)
		{
			if (edge[pos].id < l || edge[pos].id > r)
				continue;
			int u = findset(edge[pos].u);
			int v = findset(edge[pos].v);
			if (u != v)
			{
				if (col[edge[pos].u] == col[edge[pos].v])
					col[u] ^= 1;
				p[u] = v;
			}
			else if (col[edge[pos].u] == col[edge[pos].v])
				break;
		}
		printf("%d\n", pos == 0 ? -1 : edge[pos].w);
	}
	return 0;
}
