#include <cstdio>
#include <vector>

using namespace std;

const int maxn = 1e5;
vector<int> G[maxn + 1];
int col[maxn + 1];

bool dfs(int u, int c = 1)
{
	if (!col[u])
		col[u] = c;
	else
		return c == col[u];
	for (int v: G[u])
		if (!dfs(v, 3 - c))
			return false;
	return true;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	while (m--)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	bool flag = true;
	for (int i = 1; i <= n; ++i)
		if (!col[i])
			if (!dfs(i))
				flag = false;
	if (flag)
	{
		vector<int> ans1, ans2;
		for (int i = 1; i <= n; ++i)
			if (col[i] == 1)
				ans1.push_back(i);
			else
				ans2.push_back(i);
		printf("%d\n", ans1.size());
		for (int v: ans1)
			printf("%d ", v);
		puts("");
		printf("%d\n", ans2.size());
		for (int v: ans2)
			printf("%d ", v);
		puts("");
	}
	else
		puts("-1");
	return 0;
}
