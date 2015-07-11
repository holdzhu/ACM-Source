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

struct Query
{
	int d;
	Point p;
	bool operator < (const Query &rhs) const
	{
		return d > rhs.d || (d == rhs.d && p < rhs.p);
	}
};

int n, m, T;
int q[100000];
set<Query> query;
int p[1000000];
bool root[1000000];
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
		query.clear();
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				scanf("%d", &p[idx(i, j)]);
			}
		}
		scanf("%d", &T);
		for (int i = 0; i < T; ++i)
		{
			scanf("%d", &q[i]);
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				int pos = upper_bound(q, q + T, p[idx(i, j)] - 1) - q - 1;
				if (pos >= 0)
				{
					query.insert((Query){pos, (Point){i, j}});
				}
			}
		}
		memset(p, -1, sizeof p);
		int ans = 0;
		memset(root, 0, sizeof root);
		memset(q, 0, sizeof q);
		int last = T - 1;
		for (set<Query>::iterator i = query.begin(); i != query.end(); ++i)
		{
			int x = i -> p.x;
			int y = i -> p.y;
			if (i -> d < last)
			{
				for (int j = i -> d + 1; j <= last; ++j)
				{
					q[j] = ans;
				}
				last = i -> d;
			}
			p[idx(x, y)] = idx(x, y);
			for (int k = 0; k < 4; ++k)
			{
				int dx = x + d[k * 2];
				int dy = y + d[k * 2 + 1];
				if (dx >= 0 && dy >= 0 && dx < n && dy < m && p[idx(dx, dy)] >= 0)
				{
					int s = find(idx(dx, dy));
					if (root[s])
					{
						root[s] = false;
						ans--;
					}
					p[s] = idx(x, y);
				}
			}
			root[idx(x, y)] = true;
			ans++;
		}
		for (int j = 0; j <= last; ++j)
		{
			q[j] = ans;
		}
		for (int i = 0; i < T; ++i)
		{
			printf("%d ", q[i]);
		}
		printf("\n");
	}
	return 0;
}
