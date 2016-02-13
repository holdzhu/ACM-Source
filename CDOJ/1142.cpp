#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

const int mod = 1500007;

int x[1000];
vector<pair<int, int> > ab[mod];
int vis[mod];

int main()
{
	int n, tim = 0;
	while (scanf("%d", &n) == 1 && n)
	{
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", x + i);
		}
		sort(x, x + n);
		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				int s = ((x[i] + x[j]) % mod + mod) % mod;
				if (vis[s] != tim)
				{
					ab[s].clear();
					vis[s] = tim;
				}
				ab[s].push_back(make_pair(i, j));
			}
		}
		int ans = -1;
		for (int i = n - 1; i >= 0 && ans == -1; --i)
		{
			for (int j = 0; j < n && ans == -1; ++j)
			{
				if (i == j)
				{
					continue;
				}
				int s = ((x[i] - x[j]) % mod + mod) % mod;
				if (vis[s] != tim)
				{
					continue;
				}
				for (pair<int, int> p : ab[s])
				{
					if (x[p.first] + x[p.second] + x[j] == x[i] && i != p.first && i != p.second && j != p.first && j != p.second)
					{
						ans = i;
						break;
					}
				}
			}
		}
		if (ans == -1)
		{
			puts("no solution");
		}
		else
		{
			printf("%d\n", x[ans]);
		}
		tim++;
	}
	return 0;
}
