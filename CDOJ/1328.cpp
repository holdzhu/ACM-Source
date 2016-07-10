#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

const int maxn = 1e5;

vector<pair<int, int> > G[maxn + 1];
int col[maxn + 1];

bool dfs(int u, int c = 0)
{
	if (col[u] != -1)
		return col[u] == c;
	col[u] = c;
	return all_of(G[u].begin(), G[u].end(), [c](pair<int, int> &p) {
		return dfs(p.first, c ^ p.second);
	});
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int u = 1; u <= n; ++u)
	{
		int v, t;
		scanf("%d %d", &v, &t);
		--t;
		G[u].push_back({v, t});
		G[v].push_back({u, t});
		col[u] = -1;
	}
	for (int u = 1; u <= n; ++u)
		if (col[u] == -1 && !dfs(u))
		{
			puts("One face meng bi");
			return 0;
		}
	puts("Time to show my power");
	return 0;
}
