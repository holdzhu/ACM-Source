#pragma comment(linker, "/STACK:102400000,102400000")
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int n;
vector<int> G[200000];
bool vis[200000];
int ring[200000];
int cnt[200000];
int s[200000];
int mod[200000];

bool dfs(int u, int fa = -1)
{
	static int cou = 1;
	printf("%d\n", cou++);
	if (vis[u])
	{
		ring[u] = fa;
		return true;
	}
	vis[u] = true;
	for (int i = 0; i < G[u].size(); ++i)
	{
		int v = G[u][i];
		if (v == fa)
		{
			continue;
		}
		if (dfs(v, u))
		{
			if (ring[u] != -1)
			{
				return true;
			}
			else
			{
				ring[u] = fa;
				return true;
			}
		}
	}
	return false;
}

int dfs2(int u, int fa = -1)
{
	int rnt = 0;
	for (int i = 0; i < G[u].size(); ++i)
	{
		int v = G[u][i];
		if (v == fa || ring[v] != -1)
		{
			continue;
		}
		rnt += dfs2(v, u);
	}
	return cnt[u] = rnt + 1;
}

bool check(int k)
{
	int c = 0;
	int r = 0;
	memset(s, 0, sizeof s);
	s[0] = 0;
	for (int i = 0; i < n; ++i)
	{
		if (ring[i] != -1)
		{
			int t = i;
			while (1)
			{
				dfs2(t);
				r++;
				s[r] = (s[r - 1] + cnt[t]) % k;
				if (ring[t] == i)
				{
					break;
				}
				t = ring[t];
			}
			break;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		if (ring[i] == -1 && cnt[i] % k == 0)
		{
			c++;
		}
	}
	memset(mod, 0, sizeof mod);
	for (int i = 1; i <= r; ++i)
	{
		mod[s[i]]++;
	}
	int del = 0;
	for (int i = 0; i < r; ++i)
	{
		if (mod[del] + c == n / k)
		{
			return true;
		}
		mod[(s[r] + del) % k]--;
		mod[del]++;
		del = (del - s[r - i] + s[r - i - 1] + k) % k;
	}
	return false;
}

int main()
{
	freopen("5329.in", "r", stdin);
	while (scanf("%d", &n) == 1)
	{
		for (int i = 0; i < n; ++i)
		{
			G[i].clear();
		}
		for (int i = 0; i < n; ++i)
		{
			int v;
			scanf("%d", &v);
			v--;
			G[i].push_back(v);
			G[v].push_back(i);
		}
		memset(vis, false, sizeof vis);
		memset(cnt, 0, sizeof cnt);
		memset(ring, -1, sizeof ring);
		dfs(0);
		int ans = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (n % i == 0)
			{
				if (check(i))
				{
					ans++;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
