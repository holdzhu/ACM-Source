#include <cstdio>
#include <cstring>

int vis[1000000];

int main()
{
	int n, m;
	memset(vis, 0, sizeof(vis));
	vis[1] = 1;
	while (scanf("%d %d", &n, &m) == 2)
	{
		printf("%d %d ", n, m);
		int max = 0;
		if (n > m)
		{
			int t = n;
			n = m;
			m = t;
		}
		for (int i = n; i <= m; ++i)
		{
			if (!vis[i])
			{
				long long t = i;
				while (t >= 1000000 || !vis[t])
				{
					if (t % 2)
					{
						t = t * 3 + 1;
					}
					else
					{
						t >>= 1;
					}
					vis[i]++;
				}
				vis[i] += vis[t];
			}
			if (vis[i] > max)
			{
				max = vis[i];
			}
		}
		printf("%d\n", max);
	}
	return 0;
}
