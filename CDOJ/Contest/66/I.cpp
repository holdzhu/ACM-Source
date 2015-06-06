#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

int n;
long long L;
long long d[14][14];
int max1;
int max2;
int set1[7];
bool vis[7];
int pos1;
int set2[7];
int pos2;
set<long long> tail[7];

void dfs1(int x, int last, long long len)
{
	if (len > L)
	{
		return;
	}
	if (x == max1)
	{
		tail[last].insert(len);
	}
	else
	{
		for (int i = 1; i < max1; ++i)
		{
			if (!vis[i])
			{
				vis[i] = true;
				dfs1(x + 1, i, len + d[set1[i]][set1[last]]);
				vis[i] = false;
			}
		}
	}
}

bool dfs2(int x, int last, long long len)
{
	if (len > L)
	{
		return false;
	}
	if (x == max2)
	{
		for (int i = 0; i < max1; ++i)
		{
			if (tail[i].count(L - len - d[last][set1[i]]))
			{
				return true;
			}
		}
	}
	else
	{
		for (int i = 0; i < max2; ++i)
		{
			if (!vis[i])
			{
				vis[i] = true;
				if (dfs2(x + 1, set2[i], len + d[set2[i]][last]))
				{
					return true;
				}
				vis[i] = false;
			}
		}
	}
	return false;
}

bool dfs(int x)
{
	if (x == n)
	{
		memset(vis, 0, sizeof vis);
		for (int i = 0; i < max1; ++i)
		{
			tail[i].clear();
		}
		dfs1(1, 0, 0);
		memset(vis, 0, sizeof vis);
		if (dfs2(0, 0, 0))
		{
			return true;
		}
	}
	else
	{
		if (pos1 < max1)
		{
			set1[pos1++] = x;
			if (dfs(x + 1))
			{
				return true;
			}
			pos1--;
		}
		if (pos2 < max2)
		{
			set2[pos2++] = x;
			if (dfs(x + 1))
			{
				return true;
			}
			pos2--;
		}
	}
	return false;
}

int main()
{
	scanf("%d %lld", &n, &L);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			scanf("%lld", &d[i][j]);
		}
	}
	max2 = n / 2;
	max1 = n - max2;
	set1[0] = 0;
	pos1 = 1;
	pos2 = 0;
	printf("%s\n", dfs(1) ? "possible" : "impossible");
	return 0;
}
