#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Road
{
	int XOR;
	int walk;
	int drive;
};

int n;
vector<int> G[5000];
Road road[4999];
int start;
int target;
long long dp[2][5000];
bool cur;
long long startWalk;
long long last;

inline long long min1(long long a, long long b)
{
	if (a == -1)
	{
		return b;
	}
	if (b == -1)
	{
		return a;
	}
	return min(a, b);
}

bool dfs(int x, int fa, long long walkDis)
{
	if (start == x)
	{
		for (int i = 0; i < n; ++i)
		{
			if (dp[!cur][i] != -1)
			{
				dp[cur][i] = dp[!cur][i] + walkDis;
			}
		}
		startWalk = 0;
		last = dp[!cur][x];
		return true;
	}
	else
	{
		for (int i = 0; i < G[x].size(); ++i)
		{
			int v = road[G[x][i]].XOR ^ x;
			if (v != fa && dfs(v, x, walkDis + road[G[x][i]].walk))
			{
				startWalk += road[G[x][i]].walk;
				last += road[G[x][i]].drive;
				dp[cur][x] = min1(dp[cur][x], last);
				if (dp[!cur][x] != -1)
				{
					dp[cur][x] = min1(dp[cur][x], dp[!cur][x] + startWalk);
				}
				last = dp[cur][x];
				dp[cur][x] += walkDis;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	int m;
	scanf("%d %d", &n, &m);
	for (int j = 0; j < n - 1; ++j)
	{
		int u, v;
		scanf("%d %d %d %d", &u, &v, &road[j].walk, &road[j].drive);
		u--;
		v--;
		road[j].XOR = u ^ v;
		G[u].push_back(j);
		G[v].push_back(j);
	}
	memset(dp, -1, sizeof dp);
	cur = 0;
	scanf("%d", &start);
	start--;
	dp[0][start] = 0;
	for (int j = 0; j < m - 1; ++j)
	{
		scanf("%d", &target);
		target--;
		cur = !cur;
		memset(dp[cur], -1, sizeof dp[cur]);
		dfs(target, -1, 0);
		start = target;
	}
	long long ans = -1;
	for (int i = 0; i < n; ++i)
	{
		ans = min1(ans, dp[cur][i]);
	}
	printf("%lld\n", ans);
	return 0;
}