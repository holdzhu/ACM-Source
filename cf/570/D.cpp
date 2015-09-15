#include <cstdio>
#include <vector>

using namespace std;

vector<int> G[500001];
char s[500002];
vector<int> pos[500001][26];
int tm;
int in[500001];
int out[500001];

void dfs(int u, int depth)
{
	in[u] = tm++;
	for (int i = 0; i < G[u].size(); ++i)
	{
		dfs(G[u][i], depth + 1);
	}
	pos[depth][s[u] - 'a'].push_back(tm);
	out[u] = tm++;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 2; i <= n; ++i)
	{
		int t;
		scanf("%d", &t);
		G[t].push_back(i);
	}
	scanf("%s", s + 1);
	dfs(1, 1);
	for (int i = 0; i < m; ++i)
	{
		int v, h;
		scanf("%d %d", &v, &h);
		int odd = 0;
		for (int j = 0; j < 26; ++j)
		{
			int p1 = lower_bound(pos[h][j].begin(), pos[h][j].end(), in[v]) - pos[h][j].begin();
			int p2 = lower_bound(pos[h][j].begin(), pos[h][j].end(), out[v] + 1) - pos[h][j].begin();
			if (p1 != pos[h][j].size() && (p2 - p1) % 2 == 1)
			{
				odd++;
			}
		}
		puts(odd <= 1 ? "Yes" : "No");
	}
	return 0;
}
