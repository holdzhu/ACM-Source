#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

enum
{
	N,
	S
};

int n, p, m;
string name[10000];
vector<int> GA[10000];
vector<int> GB[10000];
map<string, int> ma;
int vis[10000];
char dir[2];

bool dfs(int x)
{
	for (int i = 0; i < GA[x].size(); ++i)
	{
		if (vis[GA[x][i]] == vis[x])
		{
			return false;
		}
		if (vis[GA[x][i]] == -1)
		{
			vis[GA[x][i]] = !vis[x];
			if (!dfs(GA[x][i]))
			{
				return false;
			}
		}
	}
	for (int i = 0; i < GB[x].size(); ++i)
	{
		if (vis[GB[x][i]] == !vis[x])
		{
			return false;
		}
		if (vis[GB[x][i]] == -1)
		{
			vis[GB[x][i]] = vis[x];
			if (!dfs(GB[x][i]))
			{
				return false;
			}
		}
	}
	return true;
}

bool solve()
{
	int k = ma["King"];
	cin >> dir;
	if (dir[0] == 'N')
	{
		vis[k] = N;
	}
	else
	{
		vis[k] = S;
	}
	if (dfs(k))
	{
		for (int i = 0; i < n; ++i)
		{
			if (vis[i] == -1)
			{
				vis[i] = N;
				if (!dfs(i))
				{
					return false;
				}
			}
		}
	}
	else
	{
		return false;
	}
	return true;
}

int main()
{
	memset(vis, -1, sizeof vis);
	cin >> n >> p >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> name[i];
		ma[name[i]] = i;
	}
	for (int i = 0; i < p; ++i)
	{
		string s1, s2;
		cin >> s1 >> s2;
		int u = ma[s1];
		int v = ma[s2];
		GA[u].push_back(v);
		GA[v].push_back(u);
	}
	for (int i = 0; i < m; ++i)
	{
		string s1, s2;
		cin >> s1 >> s2;
		int u = ma[s1];
		int v = ma[s2];
		GB[u].push_back(v);
		GB[v].push_back(u);
	}
	if (solve())
	{
		cout << "Yes\n"; 
		for (int i = 0; i < n; ++i)
		{
			cout << name[i] << ' ' << (vis[i] == N ? 'N' : 'S') << '\n';
		}
	}
	else
	{
		cout << "No\n";
	}
	return 0;
}
