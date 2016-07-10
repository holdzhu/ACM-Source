#include <cstdio>
#include <map>
#include <queue>

using namespace std;

map<char, int> msk;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

char s[1001];
int val[1000][1000];
int dp[1000][1000][4];

inline int get(int ori, int shift)
{
	return ((ori << shift) & 15) | (ori >> (4 - shift));
}

int main()
{
	msk['+'] = 15;
	msk['-'] = 5;
	msk['|'] = 10;
	msk['^'] = 8;
	msk['>'] = 1;
	msk['<'] = 4;
	msk['v'] = 2;
	msk['L'] = 11;
	msk['R'] = 14;
	msk['U'] = 7;
	msk['D'] = 13;
	msk['*'] = 0;
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", s);
		for (int j = 0; j < m; ++j)
		{
			val[i][j] = msk[s[j]];
			for (int k = 0; k < 4; ++k)
				dp[i][j][k] = -1;
		}
	}
	int xt, yt, xm, ym;
	scanf("%d %d %d %d", &xt, &yt, &xm, &ym);
	--xt;
	--yt;
	--xm;
	--ym;
	dp[xt][yt][0] = 0;
	queue<pair<pair<int, int>, int>> q;
	q.push({{xt, yt}, 0});
	int ans = -1;
	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dir = q.front().second;
		q.pop();
		if (x == xm && y == ym)
		{
			ans = dp[x][y][dir];
			break;
		}
		if (dp[x][y][(dir + 1) % 4] == -1)
		{
			dp[x][y][(dir + 1) % 4] = dp[x][y][dir] + 1;
			q.push({{x, y}, (dir + 1) % 4});
		}
		int nv = get(val[x][y], dir);
		for (int i = 0; i < 4; ++i)
		{
			if (nv >> i & 1)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && ny >= 0 && nx < n && ny < m)
				{
					int nnv = get(val[nx][ny], dir);
					if (nnv >> (i ^ 2) & 1)
					{
						if (dp[nx][ny][dir] == -1)
						{
							dp[nx][ny][dir] = dp[x][y][dir] + 1;
							q.push({{nx, ny}, dir});
						}
					}
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
