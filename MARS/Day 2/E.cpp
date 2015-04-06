#include <cstdio>
#include <set>
#include <map>

using namespace std;

struct Point
{
	Point(int x, int y): x(x), y(y) {}
	int x, y;
	bool operator < (const Point b) const
	{
		return x < b.x || (x == b.x && y < b.y);
	}
};

int main()
{
	int n, m, q;
	scanf("%d %d %d", &n, &m, &q);
	bool zero[n][m];
	set<Point> *r[n][m];
	for (int i = 0; i < n; ++i)
	{
		char s[n + 1];
		scanf("%s", s);
		for (int j = 0; j < m; ++j)
		{
			zero[i][j] = s[j] - '0';
			r[i][j] = new set<Point>;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int lasty = m;
			for (int x = i; x < n && lasty > j; ++x)
			{
				for (int y = j; y < lasty; ++y)
				{
					if (zero[x][y])
					{
						lasty = y;
						break;
					}
					r[i][j]->insert(Point(x, y));
				}
			}
		}
	}
	map<int, int> dp;
	int i3 = m;
	int i2 = i3 * n;
	int i1 = i2 * m;
	while (q--)
	{
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		int sum = 0;
		for (int i = a - 1; i < c; ++i)
		{
			for (int j = b - 1; j < d; ++j)
			{
				if (!dp.count(i * i1 + j * i2 + (c - 1) * i3 + (d - 1)))
				{
					int _sum = 0;
					for (set<Point>::iterator si = r[i][j]->begin(); si != r[i][j]->end(); ++si)
					{
						if (si->x >= c && si->y >= d)
						{
							break;
						}
						else if (si->x < c && si->y < d)
						{
							_sum++;
						}
					}
					dp[i * i1 + j * i2 + (c - 1) * i3 + (d - 1)] = _sum;
				}
				sum += dp[i * i1 + j * i2 + (c - 1) * i3 + (d - 1)];
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}
