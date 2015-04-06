#include <cstdio>
#include <vector>

using namespace std;

vector<int> G[100000];
int ans = 0;

int dfs(int x, int p)
{
	int size = G[x].size();
	if (p != -1)
	{
		size--;
	}
	if (size == 0)
	{
		return 1;
	}
	if (size == 1)
	{
		if (G[x][0] != p)
		{
			return dfs(G[x][0], x) + 1;
		}
		return dfs(G[x][1], x) + 1;
	}
	int max1 = 0;
	int max2 = 0;
	for (int i = 0; i < G[x].size(); ++i)
	{
		if (G[x][i] == p)
		{
			continue;
		}
		int t = dfs(G[x][i], x);
		if (t >= max1)
		{
			max2 = max1;
			max1 = t;
		}
		else if (t > max2)
		{
			max2 = t;
		}
	}
	if (max1 + max2 > ans)
	{
		ans = max1 + max2;
	}
	return max1 + 1;
}

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N - 1; ++i)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		u--;
		v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int t = dfs(0, -1);
	if (t > ans)
	{
		ans = t;
	}
	printf("%d\n", ans);
	return 0;
}
