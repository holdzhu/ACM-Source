#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int d[] = {1, 0, -1, 0, 0, 1, 0, -1};
bool vis[1000][1000];
bool notvaild[1000][1000];

struct Point
{
	int x, y;
	Point(int x = 0, int y = 0): x(x), y(y) {}
};

int X, Y, T, L, W;

bool isvaild(int x, int y)
{
	if (x < 0 || y < 0 || x >= X || y >= Y)
	{
		return false;
	}
	return !notvaild[x][y];
}

Point queue[2][1000000];
int p[2];

int main()
{
	while (scanf("%d", &X) == 1 && X != -1)
	{
		scanf("%d %d %d %d", &Y, &T, &L, &W);
		memset(vis, 0, sizeof vis);
		memset(notvaild, 0, sizeof notvaild);
		p[0] = 0;
		int ans = 0;
		for (int i = 0; i < L; ++i)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			x--;
			y--;
			queue[0][p[0]++] = Point(x, y);
			vis[x][y] = true;
			ans++;
		}
		for (int i = 0; i < W; ++i)
		{
			int x1, y1, x2, y2;
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			x1--;
			x2--;
			y1--;
			y2--;
			if (x1 == x2)
			{
				if (y1 > y2)
				{
					swap(y1, y2);
				}
				for (int j = y1; j <= y2; ++j)
				{
					notvaild[x1][j] = true;
				}
			}
			else
			{
				if (x1 > x2)
				{
					swap(x1, x2);
					swap(y1, y2);
				}
				int k = (y2 - y1) / (x2 - x1);
				for (int j = x1; j <= x2; ++j)
				{
					notvaild[j][y1 + k * (j - x1)] = true;
				}
			}
		}
		int cur = 0;
		for (int i = 0; i < T - 1; ++i)
		{
			p[!cur] = 0;
			for (int j = 0; j < p[cur]; ++j)
			{
				Point u = queue[cur][j];
				for (int k = 0; k < 4; ++k)
				{
					int x = d[k * 2] + u.x;
					int y = d[k * 2 + 1] + u.y;
					if (isvaild(x, y) && !vis[x][y])
					{
						ans++;
						vis[x][y] = true;
						queue[!cur][p[!cur]++] = Point(x, y);
					}
				}
			}
			cur = !cur;
		}
		printf("%d\n", ans);
	}
	return 0;
}
