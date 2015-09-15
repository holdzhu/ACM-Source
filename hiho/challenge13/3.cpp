#include <cstdio>
#include <vector>
#include <set>
#include <functional>

using namespace std;

int a[100000];
vector<int> G[100000];
int ans[100000];

vector<pair<int, int> > dfs(int u, int fa = -1)
{
	vector<pair<int, int> > rnt;
	for (int i = 0; i < G[u].size(); ++i)
	{
		int v = G[u][i];
		if (v == fa)
		{
			continue;
		}
		vector<pair<int, int> > d = dfs(v, u);
		vector<pair<int, int> > tmp;
		vector<pair<int, int> >::iterator it1 = rnt.begin();
		vector<pair<int, int> >::iterator it2 = d.begin();
		while (it1 != rnt.end() || it2 != d.end())
		{
			if (it1 == rnt.end())
			{
				tmp.push_back(*it2);
				it2++;
			}
			else if (it2 == d.end())
			{
				tmp.push_back(*it1);
				it1++;
			}
			else
			{
				if (it1->first == it2->first)
				{
					tmp.push_back(make_pair(it1->first, it1->second + it2->second));
					it1++;
					it2++;
				}
				else if (it1->first > it2->first)
				{
					tmp.push_back(*it2);
					it2++;
				}
				else
				{
					tmp.push_back(*it1);
					it1++;
				}
			}
		}
		rnt = tmp;
	}
	int pos = lower_bound(rnt.begin(), rnt.end(), make_pair(a[u], -1)) - rnt.begin() - 1;
	if (pos < 0)
	{
		ans[u] = 1;
		vector<pair<int, int> > tmp;
		tmp.push_back(make_pair(a[u], 1));
		for (int i = 0; i < rnt.size(); ++i)
		{
			tmp.push_back(rnt[i]);
		}
		rnt = tmp;
	}
	else
	{
		ans[u] = 1;
		vector<pair<int, int> > tmp;
		for (int i = 0; i <= pos; ++i)
		{
			tmp.push_back(rnt[i]);
			ans[u] += tmp.back().second;
		}
		tmp.push_back(make_pair(a[u], 1));
		for (int i = pos + 1; i < rnt.size(); ++i)
		{
			tmp.push_back(rnt[i]);
		}
		rnt = tmp;
	}
	return rnt;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n - 1; ++i)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	vector<pair<int, int> > rn = dfs(0);
	for (int i = 0; i < n; ++i)
	{
		if (i)
		{
			printf(" ");
		}
		printf("%d", ans[i]);
	}
	printf("\n");
	return 0;
}
