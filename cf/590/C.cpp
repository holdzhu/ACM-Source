#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
char s[1001][1001];
int t[3][1001][1001];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", s[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			t[0][i][j] = t[1][i][j] = t[2][i][j] = 1e8;
		}
	}
	for (int k = 0; k < 3; ++k)
	{
		queue<pair<int, int> > q;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (s[i][j] == '1' + k)
				{
					q.push(make_pair(i, j));
					t[k][i][j] = 0;
				}
			}
		}
		while (!q.empty())
		{
			pair<int, int> p = q.front();
			q.pop();
			int x = p.first;
			int y = p.second;
			for (int l = 0; l < 4; ++l)
			{
				int nx = x + dx[l];
				int ny = y + dy[l];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m && s[nx][ny] != '#' && t[k][nx][ny] > t[k][x][y] + (s[x][y] == '.'))
				{
					t[k][nx][ny] = t[k][x][y] + (s[x][y] == '.');
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	int ans = 1e9;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			ans = min(ans, t[0][i][j] + t[1][i][j] + t[2][i][j] + (s[i][j] == '.'));
		}
	}
	printf("%d\n", ans >= 1e8 ? -1 : ans);
	return 0;
}
