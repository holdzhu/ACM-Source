#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

struct Node
{
	int x, y, type;
	bool operator < (const Node& rhs) const
	{
		return x < rhs.x || (x == rhs.x && y < rhs.y) || (x == rhs.x && y == rhs.y && type < rhs.type);
	}
};

int w, h;
char s[1001][200];
bool top[1000][99];
bool bottom[1000][99];
bool left[1000][99];
bool right[1000][99];
bool pointvis[1001][100];
bool vis[1000][99][2];
bool airvis[1000][99];

int main()
{
	int Tank = 1;
	while (scanf("%d %d", &w, &h) == 2 && w && h)
	{
		memset(top, 0, sizeof top);
		memset(bottom, 0, sizeof bottom);
		memset(left, 0, sizeof left);
		memset(right, 0, sizeof right);
		memset(pointvis, 0, sizeof pointvis);
		memset(vis, 0, sizeof vis);
		memset(airvis, 0, sizeof airvis);
		for (int i = 0; i < h + 1; ++i)
		{
			scanf("%s", s[i]);
			for (int j = 0; j < 2 * w + 1; ++j)
			{
				if (s[i][j] == '|')
				{
					if (j / 2 < w)
					{
						left[i - 1][j / 2] = true;
					}
					if (j / 2 > 0)
					{
						right[i - 1][j / 2 - 1] = true;
					}
				}
				if (s[i][j] == '_')
				{
					if (i > 0)
					{
						bottom[i - 1][j / 2] = true;
					}
					top[i][j / 2] = true;
				}
			}
		}
		queue<Node> wall;
		wall.push((Node){0, 0, 0});
		while (!wall.empty())
		{
			Node p = wall.front();
			wall.pop();
			if (pointvis[p.x][p.y])
			{
				continue;
			}
			pointvis[p.x][p.y] = true;
			if (p.x > 0 && ((p.y < w && left[p.x - 1][p.y]) || (p.y > 0 && right[p.x - 1][p.y - 1])))
			{
				wall.push((Node){p.x - 1, p.y, 0});
			}
			if (p.x < h && ((p.y < w && left[p.x][p.y]) || (p.y > 0 && right[p.x][p.y - 1])))
			{
				wall.push((Node){p.x + 1, p.y, 0});
			}
			if (p.y > 0 && ((p.x < h && top[p.x][p.y - 1]) || (p.x > 0 && bottom[p.x - 1][p.y - 1])))
			{
				wall.push((Node){p.x, p.y - 1, 0});
			}
			if (p.y < w && ((p.x < h && top[p.x][p.y]) || (p.x > 0 && bottom[p.x - 1][p.y])))
			{
				wall.push((Node){p.x, p.y + 1, 0});
			}
		}
		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				if (top[i][j] && !pointvis[i][j])
				{
					top[i][j] = false;
				}
				if (left[i][j] && !pointvis[i][j])
				{
					left[i][j] = false;
				}
				if (bottom[i][j] && !pointvis[i + 1][j])
				{
					bottom[i][j] = false;
				}
				if (right[i][j] && !pointvis[i][j + 1])
				{
					right[i][j] = false;
				}
			}
		}
		queue<Node> q;
		queue<Node> airq;
		int ans = 0;
		for (int i = 0; i < w; ++i)
		{
			if (!top[0][i])
			{
				q.push((Node){0, i, 0});
			}
			if (!bottom[h - 1][i])
			{
				airq.push((Node){h - 1, i, 0});
			}
		}
		for (int i = 0; i < h; ++i)
		{
			if (!right[i][w - 1])
			{
				q.push((Node){i, w - 1, 0});
				airq.push((Node){i, w - 1, 0});
			}
		}
		while (!q.empty())
		{
			Node p = q.front();
			q.pop();
			if (p.x < 0 || p.x >= h || p.y < 0 || p.y >= w || vis[p.x][p.y][p.type])
			{
				continue;
			}
			vis[p.x][p.y][p.type] = true;
			if (p.type == 0)
			{
				ans++;
				if (!bottom[p.x][p.y])
				{
					q.push((Node){p.x + 1, p.y, 0});
				}
				if (!left[p.x][p.y])
				{
					q.push((Node){p.x, p.y - 1, 0});
					if (!top[p.x][p.y - 1])
					{
						q.push((Node){p.x, p.y - 1, 1});
					}
				}
				if (!right[p.x][p.y])
				{
					q.push((Node){p.x, p.y + 1, 0});
					if (!top[p.x][p.y + 1])
					{
						q.push((Node){p.x, p.y + 1, 1});
					}
				}
			}
			else
			{
				if (p.x <= 0)
				{
					continue;
				}
				if (!top[p.x][p.y])
				{
					q.push((Node){p.x, p.y, 0});
				}
				if (!left[p.x - 1][p.y])
				{
					q.push((Node){p.x, p.y - 1, 1});
				}
				if (!right[p.x - 1][p.y])
				{
					q.push((Node){p.x, p.y + 1, 1});
				}
			}
		}
		while (!airq.empty())
		{
			Node p = airq.front();
			airq.pop();
			if (p.x < 0 || p.x >= h || p.y < 0 || p.y >= w || airvis[p.x][p.y])
			{
				continue;
			}
			airvis[p.x][p.y] = true;
			if (vis[p.x][p.y][0])
			{
				ans--;
			}
			if (!top[p.x][p.y])
			{
				airq.push((Node){p.x - 1, p.y, 0});
			}
			if (!left[p.x][p.y])
			{
				airq.push((Node){p.x, p.y - 1, 0});
			}
			if (!right[p.x][p.y])
			{
				airq.push((Node){p.x, p.y + 1, 0});
			}
		}
		printf("Tank %d: %d\n", Tank++, ans);
	}
	return 0;
}
