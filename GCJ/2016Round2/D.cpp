#include <cstdio>
#include <algorithm>

using namespace std;

int N;
bool mat[25][25];
bool s[25][25];
bool vis[25];
int p[25];

bool dfs(int d)
{
	if (d == N)
		return true;
	bool flag = false;
	for (int i = 0; i < N; ++i)
	{
		if (!vis[i] && s[p[d]][i])
		{
			flag = true;
			vis[i] = true;
			if (!dfs(d + 1))
				return false;
			vis[i] = false;
		}
	}
	if (!flag)
		return false;
	return true;
}

bool solve()
{
	for (int i = 0; i < N; ++i)
		p[i] = i, vis[i] = false;
	do
	{
		if (!dfs(0))
			return false;
	}
	while (next_permutation(p, p + N));
	return true;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		scanf("%d", &N);
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				scanf("%1d", &mat[i][j]);
		int ans = N * N;
		for (int i = 0; i < (1 << (N * N)); ++i)
		{
			for (int j = 0; j < N * N; ++j)
				s[j / N][j % N] = mat[j / N][j % N] | (i >> j & 1);
			if (solve())
				ans = min(ans, __builtin_popcount(i));
		}
		printf("Case #%d: %d\n", kase, ans);
	}
	return 0;
}
