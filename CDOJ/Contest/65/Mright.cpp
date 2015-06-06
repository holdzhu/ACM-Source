#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Road
{
	int XOR;
	long long walk;
	long long drive;
};

vector<int> G[5000];
Road road[4999];
int start;
int target;
long long dis[5000][5000];
long long driveDis[5000][5000];
long long dp[2][5000];
bool cur;

inline int getSide(int x, int i)
{
	return road[G[x][i]].XOR ^ x;
}

void calcDis(int x, int fa = -1, long long d = 0)
{
	dis[start][x] = d;
	for (int i = 0; i < G[x].size(); ++i)
	{
		int v = getSide(x, i);
		if (v != fa)
		{
			calcDis(v, x, d + road[G[x][i]].walk);
		}
	}
}

void calcDrive(int x, int fa = -1, long long d = 0)
{
	driveDis[start][x] = d;
	for (int i = 0; i < G[x].size(); ++i)
	{
		int v = getSide(x, i);
		if (v != fa)
		{
			calcDrive(v, x, d + road[G[x][i]].drive);
		}
	}
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int j = 0; j < n - 1; ++j)
	{
		int u, v;
		scanf("%d %d %lld %lld", &u, &v, &road[j].walk, &road[j].drive);
		u--;
		v--;
		road[j].XOR = u ^ v;
		G[u].push_back(j);
		G[v].push_back(j);
	}
	memset(dp, -1, sizeof dp);
	memset(dis, 0, sizeof dis);
	memset(driveDis, 0, sizeof driveDis);
	cur = 0;
	for (start = 0; start < n; ++start)
	{
		calcDis(start);
		calcDrive(start);
	}
	scanf("%d", &start);
	dp[0][--start] = 0;
	for (int j = 0; j < m - 1; ++j)
	{
		scanf("%d", &target);
		target--;
		cur = !cur;
		memset(dp[cur], -1, sizeof dp[cur]);
		for (int i = 0; i < n; ++i)
		{
			if (dp[!cur][i] != -1)
			{
				dp[cur][i] = dp[!cur][i] + dis[start][target];
			}
		}
		for (int i = 0; i < n; ++i)
		{
			if (dp[!cur][i] != -1)
			{
				for (int j = 0; j < n; ++j)
				{
					if (dp[cur][j] == -1)
					{
						dp[cur][j] = dp[!cur][i] + dis[start][i] + dis[target][j] + driveDis[i][j];
					}
					else
					{
						dp[cur][j] = min(dp[cur][j], dp[!cur][i] + dis[start][i] + dis[target][j] + driveDis[i][j]);
					}
				}
			}
		}
		start = target;
	}
	long long ans = -1;
	for (int i = 0; i < n; ++i)
	{
		if (ans == -1)
		{
			ans = dp[cur][i];
		}
		else if (dp[cur][i] != -1)
		{
			ans = min(ans, dp[cur][i]);
		}
	}
	printf("%lld\n", ans);
	return 0;
}