#include <cstdio>
#include <vector>

using namespace std;

int n, m;
vector<int> G[501];
bool mat[501][501];
int col[501];
int cnt;

bool dfs(int u, int fa)
{
	cnt++;
	for (int i = 0; i < G[u].size(); ++i)
	{
		int v = G[u][i];
		if (v == fa)
			continue;
		if (col[v] == 0)
		{
			col[v] = 4 - col[u];
			if (!dfs(v, u))
				return false;
		}
		else if (col[v] + col[u] != 4)
			return false;
	}
	return true;
}

bool check()
{
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
			if (mat[i][j] && ((col[i] == 1 && col[j] == 3) || (col[i] == 3 && col[j] == 1)))
				return false;
			else if (!mat[i][j] && !((col[i] == 1 && col[j] == 3) || (col[i] == 3 && col[j] == 1)))
				return false;
	return true;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		mat[u][v] = mat[v][u] = 1;
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (!mat[i][j] && i != j)
				G[i].push_back(j);
	bool flag = true;
	int cnt2 = 0;
	for (int i = 1; i <= n; ++i)
		if (col[i] == 0)
		{
			col[i] = 1;
			cnt = 0;
			if (!dfs(i, -1))
			{
				flag = false;
				break;
			}
			if (cnt == 1)
				col[i] = 2;
			else
				cnt2++;
		}
	if (!flag || cnt2 >= 2 || !check())
	{
		puts("No");
	}
	else
	{
		puts("Yes");
		for (int i = 1; i <= n; ++i)
			putchar('a' - 1 + col[i]);
		puts("");
	}
	return 0;
}
