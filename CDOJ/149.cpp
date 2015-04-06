#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

struct cur
{
	int x, y, step;
};

const int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N, M;
		scanf("%d %d", &N, &M);
		char m[N][M + 1];
		bool vis[N][M];
		memset(vis, 0, sizeof(vis));
		queue<cur> q;
		cur p;
		int px1[26], py1[26], px2[26], py2[26];
		for (int i = 0; i < 26; ++i)
		{
			px1[i] = -1;
		}
		for (int i = 0; i < N; ++i)
		{
			scanf("%s", m[i]);
			for (int j = 0; j < M; ++j)
			{
				if (m[i][j] == 'L')
				{
					p.x = i;
					p.y = j;
					p.step = 0;
					q.push(p);
					vis[i][j] = true;
				}
				else if(m[i][j] >= 'a' && m[i][j] <= 'z')
				{
					if (px1[m[i][j] - 'a'] == -1)
					{
						px1[m[i][j] - 'a'] = i;
						py1[m[i][j] - 'a'] = j;
					}
					else
					{
						px2[m[i][j] - 'a'] = i;
						py2[m[i][j] - 'a'] = j;
					}
				}
			}
		}
		int step = 0;
		while (!q.empty())
		{
			cur c = q.front();
			q.pop();
			if (m[c.x][c.y] == 'Q')
			{
				step = c.step;
				break;
			}
			for (int i = 0; i < 4; ++i)
			{
				int dx = c.x + dir[i][0];
				int dy = c.y + dir[i][1];
				if (dx >= 0 && dx < N && dy >= 0 && dy < M && m[dx][dy] != '#' && !vis[dx][dy])
				{
					if (m[dx][dy] >= 'a' && m[dx][dy] <= 'z')
					{
						if (px1[m[dx][dy] - 'a'] == dx && py1[m[dx][dy] - 'a'] == dy)
						{
							p.x = px2[m[dx][dy] - 'a'];
							p.y = py2[m[dx][dy] - 'a'];
						}
						else
						{
							p.x = px1[m[dx][dy] - 'a'];
							p.y = py1[m[dx][dy] - 'a'];
						}
					}
					else
					{
						p.x = dx;
						p.y = dy;
					}
					p.step = c.step + 1;
					q.push(p);
					vis[dx][dy] = true;
				}
			}
		}
		if (step)
		{
			printf("%d\n", step);
		}
		else
		{
			printf("-1\n");
		}
	}
	return 0;
}
