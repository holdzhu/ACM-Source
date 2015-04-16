#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

struct Point
{
	int x, y;
	bool operator < (const Point &rhs) const
	{
		return x < rhs.x || (x == rhs.x && y < rhs.y);
	}
};

int a[1000][1000];
int n, m, T;
int q[100000];
set<Point> P[100000];
int ans[100000];
int p[1000000];
bool vis[1000000];
const int d[] = {-1, 0, 1, 0, 0, 1, 0, -1};

int find(int x)
{
	return x == p[x] ? x : p[x] = find(p[x]);
}

inline int idx(int x, int y)
{
	return x * m + y;
}

int main()
{
	int Z;
	scanf("%d", &Z);
	while (Z--)
	{
		memset(vis, 0, sizeof vis);
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				scanf("%d", &a[i][j]);
			}
		}
		scanf("%d", &T);
		for (int i = 0; i < T; ++i)
		{
			scanf("%d", &q[i]);
			P[i].clear();
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				int pos = upper_bound(q, q + T, a[i][j] - 1) - q - 1;
				if (pos >= 0)
				{
					P[pos].insert((Point){i, j});
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < n * m; ++i)
		{
			p[i] = i;
		}
		for (int i = T - 1; i >= 0; --i)
		{
			for (set<Point>::iterator j = P[i].begin(); j != P[i].end(); ++j)
			{
				int x = j -> x;
				int y = j -> y;
				set<int> t;
				for (int k = 0; k < 4; ++k)
				{
					int dx = x + d[k * 2];
					int dy = y + d[k * 2 + 1];
					if (dx >= 0 && dy >= 0 && dx < n && dy < m && vis[idx(dx, dy)])
					{
						int s = find(idx(dx, dy));
						t.insert(s);
					}
					if (dx >= 0 && dy >= 0 && dx < n && dy < m && vis[idx(dx, dy)])
					{
						int s = find(idx(dx, dy));
						p[s] = idx(x, y);
					}
				}
				if (t.size() == 0)
				{
					ans++;
				}
				else
				{
					ans -= t.size() - 1;
				}
				vis[idx(x, y)] = true;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
