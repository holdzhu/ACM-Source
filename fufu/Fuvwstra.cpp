#include <stdio.h>

const int INF = 1000000000;

int n, m, i, j, u, v, w, s, t, k;
int edge[100][100];
bool vis[100];
int dis[100];

int main()
{
	printf("点的个数：");
	scanf("%d", &n);
	printf("边的个数：");
	scanf("%d", &m);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			edge[i][j] = INF;
		}
	}
	printf("边的起点，终点和权值：\n");
	for (i = 0; i < m; i++)
	{
		scanf("%d %d %d", &u, &v, &w);
		if (edge[u][v] > w)
		{
			edge[u][v] = w;
		}
	}
	for (i = 1; i <= n; i++)
	{
		dis[i] = INF;
	}
	printf("源点：");
	scanf("%d", &s);
	dis[s] = 0;
	for (i = 0; i < n; i++)
	{
		k = -1;
		for (j = 1; j <= n; j++)
		{
			if (!vis[j] && (k == -1 || dis[j] < dis[k]))
			{
				k = j;
			}
		}
		vis[k] = 1;
		for (j = 1; j <= n; j++)
		{
			if (dis[j] > dis[k] + edge[k][j])
			{
				dis[j] = dis[k] + edge[k][j];
			}
		}
	}
	printf("距离：");
	for (i = 1; i <= n; i++)
	{
		if (dis[i] == INF)
		{
			printf("无穷大 ");
		}
		else
		{
			printf("%d ", dis[i]);
		}
	}
	printf("\n");
	return 0;
}
