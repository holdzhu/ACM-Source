#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int a[1000];
bool vis[1000];
vector<int> G[1000];
bool prime[1000001];

int dfs(int x, int pa, bool st, int &s)
{
	vis[x] = true;
	int rnt = 0;
	s++;
	for (int i = 0; i < G[x].size(); ++i)
	{
		if (!vis[G[x][i]] && G[x][i] != pa)
		{
			rnt += dfs(G[x][i], x, !st, s);
		}
	}
	return rnt + st;
}

int main()
{
	int T;
	scanf("%d", &T);
	memset(prime, -1, sizeof prime);
	prime[0] = prime[1] = false;
	for (int i = 2; i <= 1000000; ++i)
	{
		if (prime[i] && i <= 1001)
		{
			for (int j = i * i; j < 1000000; j += i)
			{
				prime[j] = false;
			}
		}
	}
	for (int kase = 0; kase < T; ++kase)
	{
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; ++i)
		{
			scanf("%d", &a[i]);
			G[i].clear();
		}
		memset(vis, 0, sizeof vis);
		for (int i = 0; i < N; ++i)
		{
			for (int j = i + 1; j < N; ++j)
			{
				if (a[i] > a[j])
				{
					if (a[i] % a[j] == 0 && prime[a[i] / a[j]] == true)
					{
						G[i].push_back(j);
						G[j].push_back(i);
					}
				}
				else
				{
					if (a[j] % a[i] == 0 && prime[a[j] / a[i]] == true)
					{
						G[i].push_back(j);
						G[j].push_back(i);
					}
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < N; ++i)
		{
			if (!vis[i])
			{
				int s = 0;
				int t = dfs(i, -1, 0, s);
				ans += max(t, s - t);
			}
		}
		printf("Case #%d: %d\n", kase + 1, ans);
	}
	return 0;
}
