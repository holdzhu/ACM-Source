#include <iostream>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

map<string, int> id;
string name[300000];
int pos = 0;
vector<int> G[300000];
pair<int, int> RMQ[600000][20];
int cur = 0;
int last[300000];

inline pair<int, int> min(pair<int, int> a, pair<int, int> b)
{
	return a.second > b.second ? b : a;
}

void dfs(int x, int h)
{
	last[x] = cur;
	RMQ[cur][0].first = x;
	RMQ[cur++][0].second = h;
	if (G[x].size())
	{
		for (vector<int>::iterator i = G[x].begin(); i != G[x].end(); ++i)
		{
			dfs(*i, h + 1);
			last[x] = cur;
			RMQ[cur][0].first = x;
			RMQ[cur++][0].second = h;
		}
	}
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
	dfs(0, 0);
	for (int i = 1; (1 << i) <= cur; ++i)
	{
		for (int j = 0; j <= cur - (1 << i); ++j)
		{
			RMQ[j][i] = min(RMQ[j][i - 1], RMQ[j + (1 << (i - 1))][i - 1]);
		}
	}
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		string a, b;
		cin >> a >> b;
		int la = last[id[a]];
		int lb = last[id[b]];
		int m;
		if (la > lb)
		{
			la ^= lb;
			lb ^= la;
			la ^= lb;
		}
		for (m = 1; 1 << m <= lb - la; ++m);
		cout << name[(min(RMQ[la][m - 1], RMQ[lb + 1 - (1 << (m - 1))][m - 1])).first] << "\n";
	}
	return 0;
}
