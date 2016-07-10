#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <queue>

using namespace std;

map<size_t, int> premp;
map<size_t, int> sufmp;
vector<int> pre[5000];
vector<int> suf[5000];
int preidx[5000];
int sufidx[5000];
int link[5000];
int rev[5000];
bool vis[5000];
bool cover[5000];

int find(int x)
{
	for (int v: pre[x])
	{
		int y = sufidx[v];
		if (!vis[y])
		{
			vis[y] = true;
			if (link[y] == -1 || find(link[y]))
			{
				link[y] = x;
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	freopen("heavy.in", "r", stdin);
	freopen("heavy.out", "w", stdout);
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	hash<string> h;
	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		size_t preh = h(s.substr(0, k));
		size_t sufh = h(s.substr(s.length() - k));
		if (!premp.count(preh))
		{
			int sz = premp.size();
			premp[preh] = sz;
		}
		pre[preidx[i] = premp[preh]].push_back(i);
		if (!sufmp.count(sufh))
		{
			int sz = sufmp.size();
			sufmp[sufh] = sz;
		}
		suf[sufidx[i] = sufmp[sufh]].push_back(i);
	}
	int ans = 0;
	for (int i = 0; i < sufmp.size(); ++i)
		link[i] = -1;
	for (int i = 0; i < premp.size(); ++i)
	{
		for (int j = 0; j < n; ++j)
			vis[j] = false;
		if (find(i))
			ans++;
	}
	printf("%d\n", ans);
	for (int i = 0; i < premp.size(); ++i)
		vis[i] = false, rev[i] = -1;
	for (int i = 0; i < sufmp.size(); ++i)
		if (link[i] != -1)
			rev[link[i]] = i;
	queue<int> q;
	for (int i = 0; i < sufmp.size(); ++i)
		if (link[i] == -1)
			q.push(i);
	while (!q.empty())
	{
		int i = q.front();
		q.pop();
		for (int u: suf[i])
		{
			int t = preidx[u];
			if (!vis[t])
			{
				vector<int> ans;
				for (int v: pre[t])
					if (!cover[v])
					{
						cover[v] = true;
						ans.push_back(v);
					}
				printf("%d", ans.size());
				for (int v: ans)
					printf(" %d", v + 1);
				puts("");
				vis[t] = true;
				if (rev[t] != -1 && link[rev[t]] != -1)
				{
					link[rev[t]] = -1;
					q.push(rev[t]);
				}
			}
		}
	}
	for (int i = 0; i < sufmp.size(); ++i)
	{
		if (link[i] != -1 && !vis[link[i]])
		{
			vector<int> ans;
			for (int v: suf[i])
				if (!cover[v])
				{
					cover[v] = true;
					ans.push_back(v);
				}
			printf("%d", ans.size());
			for (int v: ans)
				printf(" %d", v + 1);
			puts("");
		}
	}
	return 0;
}
