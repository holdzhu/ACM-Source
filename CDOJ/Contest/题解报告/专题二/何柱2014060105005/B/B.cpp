#include <cstdio>
#include <cstring>

const int d[4][4] = {{0, 1, -1, 0}, {0, -1, 1, 0}, {-1, 0, 0, -1}, {1, 0, 0, 1}};
int N, M;
char m[1000][1001];
int dp[1000][1000][4];

inline bool isvalid(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < M;
}

int dfs(int x, int y, int dir, bool counted)
{
	if (!isvalid(x, y) || m[x][y] == '0')
	{
		return 0;
	}
	if (counted && dp[x][y][dir] != -1)
	{
		return dp[x][y][dir];
	}
	int rnt = dfs(x + d[dir][counted * 2], y + d[dir][counted * 2 + 1], dir, !counted) + 1;
	if (counted)
	{
		dp[x][y][dir] = rnt;
	}
	return rnt;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		memset(dp, -1, sizeof dp);
		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; ++i)
		{
			scanf("%s", m[i]);
		}
		int ans = 0;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (m[i][j] == '1')
				{
					int sum = -3;
					for (int k = 0; k < 4; ++k)
					{
						sum += dfs(i, j, k, true);
					}
					ans = ans > sum ? ans : sum;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
