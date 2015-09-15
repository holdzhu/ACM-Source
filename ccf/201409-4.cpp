#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
int kx[1000000];
int ky[1000000];
int kc[1000000];
int dis[1001][1001];
queue<pair<pair<int, int>, int> > q;

int main()
{
	int n, m, k, d;
	scanf("%d %d %d %d", &n, &m, &k, &d);
	memset(dis, -1, sizeof dis);
	while (m--)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		dis[x][y] = 0;
		q.push(make_pair(make_pair(x, y), 0));
	}
	for (int i = 0; i < k; ++i)
	{
		scanf("%d %d %d", &kx[i], &ky[i], &kc[i]);
	}
	while (d--)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		dis[x][y] = -2;
	}
	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int s = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && dis[nx][ny] == -1)
			{
				dis[nx][ny] = s + 1;
				q.push(make_pair(make_pair(nx, ny), s + 1));
			}
		}
	}
	long long ans = 0;
	for (int i = 0; i < k; ++i)
	{
		ans += dis[kx[i]][ky[i]] * kc[i];
	}
	printf("%lld\n", ans);
	return 0;
}
