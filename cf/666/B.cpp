#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int inf = 1e8;

vector<int> G[3010];
int dis[3010][3010];
int inMax[3010][4];
int outMax[3010][4];
int ans[4];
int mx = -inf;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	while (m--)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
			dis[i][j] = -inf;
		dis[i][i] = 0;
		queue<int> q;
		q.push(i);
		while (!q.empty())
		{
			int u = q.front();
			q.pop();
			for (int v: G[u])
				if (dis[i][v] == -inf)
				{
					dis[i][v] = dis[i][u] + 1;
					q.push(v);
				}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < 4; ++j)
			inMax[i][j] = outMax[i][j] = -1;
		for (int j = 1; j <= n; ++j)
		{
			if (i == j)
				continue;
			if (inMax[i][3] == -1 || dis[inMax[i][3]][i] < dis[j][i])
			{
				inMax[i][3] = j;
				for (int k = 2; k >= 0; --k)
				{
					if (inMax[i][k] == -1 || dis[inMax[i][k]][i] < dis[j][i])
						swap(inMax[i][k], inMax[i][k + 1]);
					else
						break;
				}
			}
			if (outMax[i][3] == -1 || dis[i][outMax[i][3]] < dis[i][j])
			{
				outMax[i][3] = j;
				for (int k = 2; k >= 0; --k)
				{
					if (outMax[i][k] == -1 || dis[i][outMax[i][k]] < dis[i][j])
						swap(outMax[i][k], outMax[i][k + 1]);
					else
						break;
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (i == j)
				continue;
			for (int k = 0; k < 4; ++k)
			{
				if (inMax[i][k] == -1 || inMax[i][k] == j)
					continue;
				for (int l = 0; l < 4; ++l)
				{
					if (outMax[j][l] == -1 || outMax[j][l] == i || outMax[j][l] == inMax[i][k])
						continue;
					int newMx = dis[inMax[i][k]][i] + dis[i][j] + dis[j][outMax[j][l]];
					if (newMx > mx)
					{
						mx = newMx;
						ans[0] = inMax[i][k];
						ans[1] = i;
						ans[2] = j;
						ans[3] = outMax[j][l];
					}
				}
			}
		}
	}
	printf("%d %d %d %d\n", ans[0], ans[1], ans[2], ans[3]);
	return 0;
}
