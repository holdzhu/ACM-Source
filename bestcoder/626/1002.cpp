#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector<int> G[1001];
vector<int> ID[1001];
int p[1001];

int find(int x)
{
	return x == p[x] ? x : p[x] = find(p[x]);
}

int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		for (int i = 1; i <= n; ++i)
		{
			G[i].clear();
			ID[i].clear();
			p[i] = i;
		}
		int m = n;
		for (int i = 0; i < n; ++i)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			if (u != v)
			{
				G[u].push_back(v);
				ID[u].push_back(i);
				G[v].push_back(u);
				ID[v].push_back(i);
				int x = find(u);
				int y = find(v);
				if (x != y)
				{
					p[x] = y;
				}
			}
			else
			{
				m--;
			}
		}
		bool bl = true;
		for (int i = 2; i <= n; ++i)
		{
			if (find(i) != find(1))
			{
				bl = false;
				break;
			}
		}
		if (m < n - 1 || !bl)
		{
			puts("NO");
		}
		else if (m == n - 1)
		{
			bool flag = true;
			for (int i = 1; i <= n; ++i)
			{
				if (G[i].size() > 2)
				{
					flag = false;
					break;
				}
			}
			puts(flag ? "YES" : "NO");
		}
		else
		{
			bool flag = false;
			for (int i = 0; i < m; ++i)
			{
				flag = true;
				for (int j = 1; j <= n; ++j)
				{
					int cnt = 0;
					for (int k = 0; k < G[j].size(); ++k)
					{
						if (ID[j][k] != i)
						{
							cnt++;
						}
					}
					if (cnt > 2)
					{
						flag = false;
						break;
					}
				}
				if (flag)
				{
					break;
				}
			}
			puts(flag ? "YES" : "NO");
		}
	}
	return 0;
}
