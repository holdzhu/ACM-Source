#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 1e5;

int n;
vector<pair<pair<int, int>, int> > G[maxn + 1];
int it[maxn + 1];
vector<pair<int, int> > ans;

int dfs(int u, int tim)
{
	if (u == n - 1)
		return tim;
	int ret = 1e9;
	for (; it[u] >= 0 && G[u][it[u]].first.first >= tim; --it[u])
	{
		ret = min(ret, dfs(G[u][it[u]].second, -G[u][it[u]].first.second));
	}
	return ret;
}

int readtime()
{
	int h, m;
	scanf("%d:%d", &h, &m);
	return h * 60 + m;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int t;
		scanf("%d", &t);
		it[i] = t - 1;
		while (t--)
		{
			int a = readtime();
			int b = -readtime();
			int v;
			scanf("%d", &v);
			G[i].push_back(make_pair(make_pair(a, b), v - 1));
		}
		sort(G[i].begin(), G[i].end());
	}
	for (; it[0] >= 0; --it[0])
	{
		int t = dfs(G[0][it[0]].second, -G[0][it[0]].first.second);
		if (t < 1e9)
		{
			if (ans.size() && ans.back().first == G[0][it[0]].first.first && ans.back().second > t)
				ans.back().second = t;
			else if (ans.empty() || ans.back().second > t)
				ans.push_back(make_pair(G[0][it[0]].first.first, t));
		}
		
	}
	printf("%d\n", (int)ans.size());
	for (int i = ans.size() - 1; i >= 0; --i)
	{
		printf("%02d:%02d %02d:%02d\n", ans[i].first / 60, ans[i].first % 60, ans[i].second / 60, ans[i].second % 60);
	}
	return 0;
}
