#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

bool vis[400];
int p[400];
bool e[400][400];

bool cmp(const int& a, const int& b)
{
	return vis[a] < vis[b];
}

int main()
{
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	memset(vis, 0, sizeof vis);
	for (int i = 0; i < k; ++i)
	{
		int a;
		scanf("%d", &a);
		vis[a - 1] = true;
	}
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		if (vis[i])
		{
			cnt++;
		}
	}
	if (cnt == n)
	{
		printf("No\n");
	}
	else
	{
		int maxe = (n - 1) * (n - 2) / 2 + n - cnt;
		if (maxe < m)
		{
			printf("No\n");
		}
		else
		{
			memset(e, 0, sizeof e);
			int ecnt = 0;
			int idx = 0;
			for (int i = 0; i < n; ++i)
			{
				p[i] = i;
				if (vis[i])
				{
					idx = i;
				}
			}
			swap(p[0], p[idx]);
			sort(p + 1, p + n, cmp);
			for (int i = 0; i < n - 1; ++i)
			{
				printf("%d %d\n", p[i] + 1, p[i + 1] + 1);
				e[i][i + 1] = true;
				ecnt++;
			}
			for (int i = 1; i < n && ecnt < m; ++i)
			{
				for (int j = i + 1; j < n && ecnt < m; ++j)
				{
					if (!e[i][j])
					{
						e[i][j] = true;
						printf("%d %d\n", p[i] + 1, p[j] + 1);
						ecnt++;
					}
				}
			}
			for (int i = 2; i < n && ecnt < m; ++i)
			{
				printf("%d %d\n", p[0] + 1, p[i] + 1);
				ecnt++;
			}
		}
	}
	return 0;
}
