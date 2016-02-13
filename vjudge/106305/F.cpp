#include <cstdio>
#include <algorithm>

using namespace std;

int N;
long long target;
int ans = 1e9;

int tmp[50][50];

void dfs(long long cur, int st)
{
	if ((cur & target) == target)
	{
		ans = min(ans, st);
		return;
	}
	if (N - __builtin_popcountll(cur & target) + st >= ans)
		return;
	int c = 0;
	for (int i = 1; i <= 42; ++i)
		if (cur >> i & 1)
			tmp[st][c++] = i;
	for (int i = 0; i < c; ++i)
	{
		for (int j = 1; (tmp[st][i] << j) <= 42; ++j)
			if (!(cur >> (tmp[st][i] << j) & 1))
				dfs(cur | (1ll << (tmp[st][i] << j)), st + 1);
		for (int j = i; j < c; ++j)
		{
			if (tmp[st][i] + tmp[st][j] >= 2 && tmp[st][i] + tmp[st][j] <= 42
				&& !(cur >> (tmp[st][i] + tmp[st][j]) & 1))
				dfs(cur | (1ll << (tmp[st][i] + tmp[st][j])), st + 1);
			if (tmp[st][j] - tmp[st][i] >= 2 && tmp[st][j] - tmp[st][i] <= 42
				&& !(cur >> (tmp[st][j] - tmp[st][i]) & 1))
				dfs(cur | (1ll << (tmp[st][j] - tmp[st][i])), st + 1);
		}
	}
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		int t;
		scanf("%d", &t);
		target |= 1ll << t;
	}
	dfs(2, 0);
	printf("%d\n", ans);
	return 0;
}
