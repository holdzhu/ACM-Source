#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

int n, m;
int a[100000];
int b[100000];
int idc;
map<int, int> id;
vector<pair<int, int> > vp1[1200000];
vector<pair<int, int> > vp2[1200000];

int getId(int x)
{
	if (!id.count(x))
	{
		vp1[idc].clear();
		vp2[idc].clear();
		id[x] = idc++;
	}
	return id[x];
}

void solve()
{
	idc = 0;
	id.clear();
	vector<pair<int, int> > g;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < g.size(); ++j)
		{
			g[j].first = __gcd(g[j].first, a[i]);
		}
		g.push_back(make_pair(a[i], i));
		vector<pair<int, int> > tmp;
		for (int j = 0; j < g.size(); ++j)
		{
			if (j == g.size() - 1 || g[j].first != g[j + 1].first)
			{
				tmp.push_back(g[j]);
			}
		}
		g = tmp;
		int pos = 0;
		for (int j = 0; j < g.size(); ++j)
		{
			vp1[getId(g[j].first)].push_back(make_pair(i - pos + 1, i - g[j].second + 1));
			pos = g[j].second + 1;
		}
	}
	g.clear();
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < g.size(); ++j)
		{
			g[j].first = __gcd(g[j].first, b[i]);
		}
		g.push_back(make_pair(b[i], i));
		vector<pair<int, int> > tmp;
		for (int j = 0; j < g.size(); ++j)
		{
			if (j == g.size() - 1 || g[j].first != g[j + 1].first)
			{
				tmp.push_back(g[j]);
			}
		}
		g = tmp;
		int pos = 0;
		for (int j = 0; j < g.size(); ++j)
		{
			vp2[getId(g[j].first)].push_back(make_pair(i - pos + 1, i - g[j].second + 1));
			pos = g[j].second + 1;
		}
	}
	int len = 0;
	for (int i = 0; i < idc; ++i)
	{
		sort(vp1[i].begin(), vp1[i].end(), greater<pair<int, int> >());
		sort(vp2[i].begin(), vp2[i].end(), greater<pair<int, int> >());
		int p = 0;
		for (int j = 0; j < vp1[i].size(); ++j)
		{
			while (p < vp2[i].size() && vp2[i][p].first >= vp1[i][j].first)
			{
				if (vp1[i][j].first >= vp2[i][j].second)
				{
					len = max(len, vp1[i][j].first);
					break;
				}
				p++;
			}
			if (len >= vp1[i][j].first)
			{
				break;
			}
		}
		p = 0;
		for (int j = 0; j < vp2[i].size(); ++j)
		{
			while (p < vp1[i].size() && vp1[i][p].first >= vp2[i][j].first)
			{
				if (vp2[i][j].first >= vp1[i][j].second)
				{
					len = max(len, vp2[i][j].first);
					break;
				}
				p++;
			}
			if (len >= vp2[i][j].first)
			{
				break;
			}
		}
	}
	if (len == 0)
	{
		printf("0 0\n");
		return;
	}
	long long ans = 0;
	for (int i = 0; i < idc; ++i)
	{
		long long a = 0;
		long long b = 0;
		for (int j = 0; j < vp1[i].size(); ++j)
		{
			if (vp1[i][j].first >= len && vp1[i][j].second <= len)
			{
				a++;
			}
		}
		for (int j = 0; j < vp2[i].size(); ++j)
		{
			if (vp2[i][j].first >= len && vp2[i][j].second <= len)
			{
				b++;
			}
		}
		ans += a * b;
	}
	printf("%d %lld\n", len, ans);
}

int main()
{
	while (scanf("%d %d", &n, &m) == 2)
	{
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < m; ++i)
		{
			scanf("%d", &b[i]);
		}
		solve();
	}
	return 0;
}
