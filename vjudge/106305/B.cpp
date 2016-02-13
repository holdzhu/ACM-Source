#include <cstdio>
#include <vector>

using namespace std;

vector<int> G[10];
vector<pair<int, double> > mat[10240];
pair<int, int> f[10240];
int id[1024][10];
int cnt;
long double dp[2][10240];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	while (m--)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for (int i = 0; i < (1 << n); ++i)
		if (i == (1 << n) - 1)
			for (int j = 0; j < n; ++j)
				id[i][j] = cnt;
		else
			for (int j = 0; j < n; ++j)
				if ((i & 1) && (i >> j & 1))
				{
					id[i][j] = cnt;
					f[cnt++] = {i, j};
				}
				else
					id[i][j] = -1;
	for (int i = 0; i < cnt; ++i)
		for (int v: G[f[i].second])
			mat[i].push_back({id[f[i].first | (1 << v)][v], 1.0 / G[f[i].second].size()});
	auto &x = dp[0], &y = dp[1];
	y[0] = 1;
	long double ans = 0;
	for (int it = 1; it < 1e4; ++it)
	{
		swap(x, y);
		for (int i = 0; i <= cnt; ++i)
			y[i] = 0;
		for (int i = 0; i < cnt; ++i)
			for (auto p: mat[i])
				y[p.first] += x[i] * p.second;
		ans += y[cnt] * it;
	}
	printf("%.6f\n", (double)ans);
	return 0;
}
