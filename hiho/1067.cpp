#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <set>

using namespace std;

map<string, int> id;
string name[300000];
int pos = 0;
vector<int> G[300000];
int p[300000];
bool vis[300000];
vector<pair<int, int> > query[300000];
int ans[300000];

int find(int x)
{
	return x == p[x] ? x : p[x] = find(p[x]);
}

void dfs(int x, int pa)
{
	p[x] = x;
	vis[x] = true;
	if (query[x].size())
	{
		for (vector<pair<int, int> >::iterator i = query[x].begin(); i != query[x].end(); ++i)
		{
			if (vis[i->first])
			{
				ans[i->second] = find(i->first);
			}
		}
	}
	if (G[x].size())
	{
		for (vector<int>::iterator i = G[x].begin(); i != G[x].end(); ++i)
		{
			dfs(*i, x);
		}
	}
	p[x] = pa;
}

int main()
{
	int N, M;
	cin >> N;
	while (N--)
	{
		string a, b;
		cin >> a >> b;
		if (!id.count(a))
		{
			name[pos] = a;
			id[a] = pos++;
		}
		if (!id.count(b))
		{
			name[pos] = b;
			id[b] = pos++;
		}
		G[id[a]].push_back(id[b]);
	}
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		string a, b;
		cin >> a >> b;
		query[id[a]].push_back(make_pair(id[b], i));
		query[id[b]].push_back(make_pair(id[a], i));
	}
	dfs(0, -1);
	for (int i = 0; i < M; ++i)
	{
		cout << name[ans[i]] << "\n";
	}
	return 0;
}
