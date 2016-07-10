#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

int ans;
set<pair<int, int> > s[6];
pair<int, int> p[6][6];
bool vis[1000];

void dfs(int d, int cur)
{
	if (d == 6)
		ans = max(ans, cur);
	else for (int i = 0; i < 6; ++i)
		if (!vis[p[d][i].second])
		{
			vis[p[d][i].second] = true;
			dfs(d + 1, cur + p[d][i].first);
			vis[p[d][i].second] = false;
		}
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < 6; ++j)
		{
			int t;
			scanf("%d", &t);
			s[j].insert({t, i});
		}
	for (int i = 0; i < 6; ++i)
	{
		auto it = s[i].end();
		for (int j = 0; j < 6; ++j)
			p[i][j] = *--it;
	}
	dfs(0, 0);
	printf("%d\n", ans);
	return 0;
}
