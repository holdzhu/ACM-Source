#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int d[] = {-1, 0, 0, -1, 1, 0, 0, 1};
char s[2000][2001];
int in[2000][2000];
int pa[2000][2000];

struct cmp
{
	bool operator() (pair<int, int> a, pair<int, int> b)
	{
		return in[a.first][a.second] > in[b.first][b.second];
	}
};

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", s[i]);
	}
	memset(in, 0, sizeof(in));
	memset(pa, 0, sizeof(pa));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (s[i][j] == '.')
			{
				for (int k = 0; k < 2; ++k)
				{
					int dx = i + d[k * 2];
					int dy = j + d[k * 2 + 1];
					if (dx >= 0 && dy >= 0 && s[dx][dy] == '.')
					{
						in[i][j]++;
						in[dx][dy]++;
					}
				}
			}
		}
	}
	priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> q;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (s[i][j] == '.')
			{
				q.push(make_pair(i, j));
			}
		}
	}
	bool flag = true;
	while (!q.empty())
	{
		pair<int, int> p = q.top();
		q.pop();
		// printf("%d %d %d %d\n", p.first, p.second, in[p.first][p.second], pa[p.first][p.second]);
		if (pa[p.first][p.second])
		{
			continue;
		}
		if (in[p.first][p.second] > 1)
		{
			flag = false;
			break;
		}
		bool b = false;
		for (int i = 0; i < 4; ++i)
		{
			int dx = p.first + d[i * 2];
			int dy = p.second + d[i * 2 + 1];
			if (dx >= 0 && dy >= 0 && dx < n && dy < m && s[dx][dy] == '.' && !pa[dx][dy])
			{
				// printf("%d %d %d %d %d\n", p.first, p.second, dx, dy, i);
				pa[p.first][p.second] = i + 1;
				pa[dx][dy] = (i + 2) % 4 + 1;
				for (int j = 0; j < 4; ++j)
				{
					int ddx = dx + d[j * 2];
					int ddy = dy + d[j * 2 + 1];
					if (ddx >= 0 && ddy >= 0 && ddx < n && ddy < n && s[ddx][ddy] == '.')
					{
						in[ddx][ddy]--;
					}
				}
				b = true;
				break;
			}
		}
		if (!b)
		{
			flag = false;
			break;
		}
	}
	if (flag)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (pa[i][j] == 0)
				{
					printf("*");
				}
				else if (pa[i][j] == 1)
				{
					printf("v");
				}
				else if (pa[i][j] == 2)
				{
					printf(">");
				}
				else if (pa[i][j] == 3)
				{
					printf("^");
				}
				else
				{
					printf("<");
				}
			}
			printf("\n");
		}
	}
	else
	{
		printf("Not unique\n");
	}
	return 0;
}
