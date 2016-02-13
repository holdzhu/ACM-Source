#include <cstdio>
#include <algorithm>

using namespace std;

char s[1000][1001];
int dis[2000];
int mat[2000][2000];
bool vis[2000];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%s", s[i]);
	for (int i = 0; i < n + m; ++i)
		for (int j = 0; j < n + m; ++j)
			mat[i][j] = 1e9;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (s[i][j] == '#')
				mat[i][j + n] = mat[j + n][i] = 1;
	for (int i = 0; i < n + m; ++i)
		dis[i] = 1e9;
	dis[0] = 0;
	for (int i = 0; i < n + m; ++i)
	{
		int id = -1;
		for (int j = 0; j < n + m; ++j)
			if (!vis[j] && (id == -1 || dis[id] > dis[j]))
				id = j;
		for (int j = 0; j < n + m; ++j)
			dis[j] = min(dis[j], dis[id] + mat[id][j]);
		vis[id] = true;
	}
	printf("%d\n", dis[n - 1] < 1e9 ? dis[n - 1] : -1);
	return 0;
}
