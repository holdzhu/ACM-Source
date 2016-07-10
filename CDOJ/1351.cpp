#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

vector<pair<int, int>> G[500];

const int inf = 1e9;
int N;
int dp1[500][501];
int dp2[500][501];
int pre[500][501];
int suf[500][501];
int tmp[501];

inline void init(int *dp)
{
	fill(dp + 1, dp + N + 1, inf);
	dp[0] = 0;
}

inline void conv(int *A, int *B, int *C)
{
	for (int i = N; i >= 0; --i)
	{
		C[i] = A[i] + B[0];
		for (int j = 0; j < i; ++j)
			C[i] = min(C[i], A[j] + B[i - j]);
	}
}

inline void add(int *dp, int val)
{
	for (int i = N; i > 0; --i)
		dp[i] = dp[i - 1] + val;
	dp[0] = 0;
}

inline void dbl(int *dp)
{
	for (int i = 0; i <= N; ++i)
		dp[i] = min(inf, dp[i] << 1);
}

inline void update(int *dp, int *s)
{
	for (int i = 0; i <= N; ++i)
		dp[i] = min(dp[i], s[i]);
}

void dfs(int u, int fa = -1)
{
	G[u].erase(remove_if(G[u].begin(), G[u].end(),
						 [fa](pair<int, int> &p) { return p.first == fa; }),
			   G[u].end());
	for_each(G[u].begin(), G[u].end(), [u, fa](pair<int, int> &p) {
		dfs(p.first, u);
		add(dp1[p.first], p.second);
		add(dp2[p.first], p.second);
	});
	init(pre[0]);
	for (int i = 0; i < G[u].size(); ++i)
		conv(pre[i], dp1[G[u][i].first], pre[i + 1]);
	init(suf[G[u].size()]);
	for (int i = (int)G[u].size() - 1; i >= 0; --i)
		conv(suf[i + 1], dp1[G[u][i].first], suf[i]);
	copy(suf[0], suf[0] + N + 1, dp1[u]);
	init(dp2[u]);
	for (int i = 0; i < G[u].size(); ++i)
	{
		conv(pre[i], suf[i + 1], tmp);
		dbl(tmp);
		conv(tmp, dp2[G[u][i].first], tmp);
		update(dp2[u], tmp);
	}
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N - 1; ++i)
	{
		int u, v, d;
		scanf("%d %d %d", &u, &v, &d);
		G[u].emplace_back(v, d);
		G[v].emplace_back(u, d);
	}
	dfs(0);
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int x;
		scanf("%d", &x);
		printf("%d\n", upper_bound(dp2[0], dp2[0] + N + 1, x) - dp2[0]);
	}
	return 0;
}
