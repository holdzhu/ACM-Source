#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

struct Point
{
	int x, y;
};

struct Node
{
	int step;
	Point point;
};

struct cmp
{
	bool operator() (Node a, Node b)
	{
		return a.step > b.step || (a.step == b.step && (a.point.x < b.point.x || (a.point.x == b.point.x && a.point.y < b.point.y)));
	}
};

const int d[] = {1, 0, -1, 0, 0, 1, 0, -1};
Point pa[100][100];
char s[100][101];
bool vis[100][100];
int t;

void print(int x, int y)
{
	if (x || y)
	{
		print(pa[x][y].x, pa[x][y].y);
		printf("%ds:(%d,%d)->(%d,%d)\n", ++t, pa[x][y].x, pa[x][y].y, x, y);
		for (int i = 0; i < s[x][y] - '0'; ++i)
		{
			printf("%ds:FIGHT AT (%d,%d)\n", ++t, x, y);
		}
	}
}

int main()
{
	int N, M;
	while (scanf("%d %d", &N, &M) == 2)
	{
		for (int i = 0; i < N; ++i)
		{
			scanf("%s", s[i]);
		}
		memset(vis, 0, sizeof(vis));
		priority_queue<Node, vector<Node>, cmp> q;
		vis[0][0] = true;
		if (s[0][0] == '.')
		{
			q.push((Node) {0, (Point) {0, 0}});
		}
		else
		{
			q.push((Node) {s[0][0] - '0', (Point) {0, 0}});
		}
		int flag = 0;
		while (!q.empty())
		{
			Node p = q.top();
			q.pop();
			if (p.point.x == N - 1 && p.point.y == M - 1)
			{
				flag = p.step;
				break;
			}
			for (int i = 0; i < 4; ++i)
			{
				int dx = p.point.x + d[i * 2];
				int dy = p.point.y + d[i * 2 + 1];
				if (!vis[dx][dy] && dx >= 0 && dy >= 0 && dx < N && dy < M && s[dx][dy] != 'X')
				{
					int ds = 0;
					vis[dx][dy] = true;
					pa[dx][dy].x = p.point.x;
					pa[dx][dy].y = p.point.y;
					if (s[dx][dy] == '.')
					{
						ds = 1;
					}
					else
					{
						ds = s[dx][dy] - '0' + 1;
					}
					q.push((Node) {p.step + ds, (Point) {dx, dy}});
				}
			}
		}
		if (flag)
		{
			printf("It takes %d seconds to reach the target position, let me show you the way.\n", flag);
			t = 0;
			if (s[0][0] != '.')
			{
				for (int i = 0; i < s[0][0] - '0'; ++i)
				{
					printf("%ds:FIGHT AT (0,0)\n", ++t);
				}
			}
			print(N - 1, M - 1);
		}
		else
		{
			printf("God please help our poor hero.\n");
		}
		printf("FINISH\n");
	}
	return 0;
}
