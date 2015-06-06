#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

enum
{
	WALK,
	DRIVE
};

struct Road
{
	int XOR;
	int walk;
	int drive;
};

vector<int> G[5000];
Road road[4999];
int route[5000];
int back[5000];
int pos;
int fa[5000];
long long dp[5000][2];

void addRoute(int x)
{
	if (fa[x] != 100000000)
	{
		int v = road[fa[x]].XOR ^ x;
		addRoute(v);
		printf("%d->%d\n", v, x);
		if (route[pos - 2] == x)
		{
			pos--;
			dp[route[pos - 1]][WALK] += dp[route[pos]][WALK] + road[fa[x]].walk * 2;
			dp[route[pos - 1]][DRIVE] += min(dp[route[pos]][WALK] + min(road[fa[x]].walk, road[fa[x]].drive) * 2, dp[route[pos]][DRIVE] + road[fa[x]].drive * 2);
		}
		else
		{
			back[x] = fa[x];
			route[pos++] = x;
			dp[x][WALK] = 0;
			dp[x][DRIVE] = 0;
		}
	}
}

void go(int x)
{
	memset(fa, -1, sizeof fa);
	queue<int> q;
	q.push(route[pos - 1]);
	fa[route[pos - 1]] = 100000000;
	while (!q.empty())
	{
		int p = q.front();
		q.pop();
		if (p == x)
		{
			addRoute(p);
			break;
		}
		for (int i = 0; i < G[p].size(); ++i)
		{
			int v = road[G[p][i]].XOR ^ p;
			if (fa[v] == -1)
			{
				fa[v] = G[p][i];
				q.push(v);
			}
		}
	}
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n - 1; ++i)
	{
		int u, v;
		scanf("%d %d %d %d", &u, &v, &road[i].walk, &road[i].drive);
		u--;
		v--;
		road[i].XOR = u ^ v;
		G[u].push_back(i);
		G[v].push_back(i);
	}
	route[0] = 0;
	pos = 1;
	memset(dp, 0, sizeof dp);
	for (int i = 0; i < m; ++i)
	{
		int t;
		scanf("%d", &t);
		go(t - 1);
		for (int i = 0; i < pos; ++i)
		{
			printf("%d %lld %lld   ", i, dp[route[i]][WALK], dp[route[i]][DRIVE]);
		}
		printf("\n");
	}
	while (pos > 1)
	{
		pos--;
		dp[route[pos - 1]][WALK] += dp[route[pos]][WALK] + road[back[route[pos]]].walk;
		dp[route[pos - 1]][DRIVE] += min(dp[route[pos]][WALK] + min(road[back[route[pos]]].drive, road[back[route[pos]]].walk), dp[route[pos]][DRIVE] + road[back[route[pos]]].drive);
		for (int i = 0; i < pos; ++i)
		{
			printf("%d %lld %lld   ", i, dp[route[i]][WALK], dp[route[i]][DRIVE]);
		}
		printf("\n");
	}
	printf("%lld\n", dp[0][DRIVE]);
	return 0;
}
