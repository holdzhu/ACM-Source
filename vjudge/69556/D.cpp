#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>

using namespace std;

int nums[17];
int pos;
bool vis[65536];
int ans[65536];
int n;

int countbit(int x)
{
	return x == 0 ? 0 : countbit(x >> 1) + x % 2;
}

bool dfs(int p, int l, int c, int lp)
{
	int r;
	if (p == pos)
	{
		ans[pos--] = l;
		return true;
	}
	if (c == 0 || nums[c - 1] == 0)
	{
		for (int i = lp + 1; i < n; ++i)
		{
			if ((l >> i) % 2 == 0 && !vis[r = l + (1 << i)])
			{
				vis[r] = true;
				nums[c + 1]--;
				if (dfs(p + 1, r, c + 1, i))
				{
					ans[pos--] = l;
					return true;
				}
				vis[r] = false;
				nums[c + 1]++;
			}
		}
		for (int i = 0; i < lp + 1; ++i)
		{
			if ((l >> i) % 2 == 0 && !vis[r = l + (1 << i)])
			{
				vis[r] = true;
				nums[c + 1]--;
				if (dfs(p + 1, r, c + 1, i))
				{
					ans[pos--] = l;
					return true;
				}
				vis[r] = false;
				nums[c + 1]++;
			}
		}
	}
	else
	{
		for (int i = lp + 1; i < n; ++i)
		{
			if ((l >> i) % 2 == 1 && !vis[r = l - (1 << i)])
			{
				vis[r] = true;
				nums[c - 1]--;
				if (dfs(p + 1, r, c - 1, i))
				{
					ans[pos--] = l;
					return true;
				}
				vis[r] = false;
				nums[c - 1]++;
			}
		}
		for (int i = 0; i < lp + 1; ++i)
		{
			if ((l >> i) % 2 == 1 && !vis[r = l - (1 << i)])
			{
				vis[r] = true;
				nums[c - 1]--;
				if (dfs(p + 1, r, c - 1, i))
				{
					ans[pos--] = l;
					return true;
				}
				vis[r] = false;
				nums[c - 1]++;
			}
		}
	}
	return false;
}

int main()
{
	scanf("%d", &n);
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i < 1 << n; ++i)
	{
		nums[countbit(i)]++;
	}
	pos = (1 << n) - 1;
	dfs(0, 0, 0, n - 1);
	char s[n + 1];
	for (int i = 0; i < 1 << n; ++i)
	{
		itoa(ans[i], s, 2);
		printf("%s\n", s);
	}
	return 0;
}
