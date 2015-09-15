#include <cstdio>
#include <vector>
#include <set>
#include <queue>

using namespace std;

vector<int> clauses[200000];
vector<pair<bool, int> > var[200001];
int ans[200001];
bool visc[200001];
vector<int> dbl;
set<pair<bool, int> > last[200001];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		int t;
		scanf("%d", &t);
		for (int j = 0; j < t; ++j)
		{
			int tt;
			scanf("%d", &tt);
			clauses[i].push_back(tt);
			if (tt > 0)
			{
				var[tt].push_back(make_pair(1, i));
			}
			else
			{
				var[-tt].push_back(make_pair(0, i));
			}
		}
	}
	for (int i = 1; i <= m; ++i)
	{
		if (var[i].size() == 0)
		{
			ans[i] = 1;
		}
		else if (var[i].size() == 1)
		{
			ans[i] = var[i][0].first;
			visc[var[i][0].second] = true;
		}
		else
		{
			if (var[i][0].first == var[i][1].first)
			{
				ans[i] = var[i][0].first;
				visc[var[i][0].second] = true;
				visc[var[i][1].second] = true;
			}
			else
			{
				last[var[i][0].second].insert(make_pair(var[i][0].first, i));
				last[var[i][1].second].insert(make_pair(var[i][1].first, i));
				dbl.push_back(i);
			}
		}
	}
	queue<pair<int, int> > q;
	for (int i = 0; i < n; ++i)
	{
		if (!visc[i])
		{
			if (last[i].size() == 0)
			{
				puts("NO");
				return 0;
			}
			else if (last[i].size() == 1)
			{
				q.push(make_pair(i, last[i].begin()->second));
				last[i].clear();
			}
		}
	}
	while (!q.empty())
	{
		pair<int, int> t = q.front();
		q.pop();
		visc[t.first] = true;
		int u = t.second;
		int ii = 1;
		if (var[u][0].second != t.first)
		{
			ii = 0;
		}
		ans[u] = var[u][1 - ii].first;
		last[var[u][ii].second].erase(make_pair(var[u][ii].first, u));
		if (visc[var[u][ii].second])
		{
			continue;
		}
		if (last[var[u][ii].second].size() == 0)
		{
			puts("NO");
			return 0;
		}
		else if (last[var[u][ii].second].size() == 1)
		{
			q.push(make_pair(var[u][ii].second, last[var[u][ii].second].begin()->second));
			last[var[u][ii].second].clear();
		}
	}
	for (int i = 0; i < n; ++i)
	{
		if (last[i].size() > 0)
		{
			q.push(make_pair(i, last[i].begin()->second));
			last[i].clear();
			while (!q.empty())
			{
				pair<int, int> t = q.front();
				q.pop();
				visc[t.first] = true;
				int u = t.second;
				int ii = 1;
				if (var[u][0].second != t.first)
				{
					ii = 0;
				}
				ans[u] = var[u][1 - ii].first;
				last[var[u][ii].second].erase(make_pair(var[u][ii].first, u));
				if (visc[var[u][ii].second])
				{
					continue;
				}
				if (last[var[u][ii].second].size() == 0)
				{
					puts("NO");
					return 0;
				}
				else if (last[var[u][ii].second].size() == 1)
				{
					q.push(make_pair(var[u][ii].second, last[var[u][ii].second].begin()->second));
					last[var[u][ii].second].clear();
				}
			}
		}
	}
	puts("YES");
	for (int i = 1; i <= m; ++i)
	{
		printf("%d", ans[i]);
	}
	puts("");
	return 0;
}
