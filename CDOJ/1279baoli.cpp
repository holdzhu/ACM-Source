#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int ans;
pair<int, int> p[6][1000];
int mx[6];
bool vis[1000];

void dfs(int i, int cur)
{
	if (cur + mx[i] <= ans)
		return;
	if (i == 6)
		ans = max(ans, cur);
	else for (int j = n - 1; j >= n - 6; --j)
		if (!vis[p[i][j].second])
		{
			vis[p[i][j].second] = true;
			dfs(i + 1, cur + p[i][j].first);
			vis[p[i][j].second] = false;
		}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < 6; ++j)
			scanf("%d", &p[j][i].first), p[j][i].second = i, mx[j] = max(mx[j], p[j][i].first);
	for (int i = 0; i < 6; ++i)
		sort(p[i], p[i] + n);
	for (int i = 4; i >= 0; --i)
		mx[i] += mx[i + 1];
	dfs(0, 0);
	printf("%d\n", ans);
	return 0;
}
