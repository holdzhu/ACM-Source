#include <cstdio>
#include <vector>

using namespace std;

vector<int> G[10];
double dp[2][1024][10];

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
	auto &x = dp[0], &y = dp[1];
	y[1][0] = 1;
	double ans = 0;
	for (int it = 1; it < 1e4; ++it)
	{
		swap(x, y);
		for (int i = 0; i < (1 << n); ++i)
			for (int j = 0; j < n; ++j)
				y[i][j] = 0;
		for (int i = 0; i < (1 << n) - 1; ++i)
			for (int u = 0; u < n; ++u)
				if (i >> u & 1)
					for (int v: G[u])
						y[i | (1 << v)][v] += x[i][u] / G[u].size();
		for (int i = 0; i < n; ++i)
			ans += it * y[(1 << n) - 1][i];
	}
	printf("%.6f\n", ans);
	return 0;
}
