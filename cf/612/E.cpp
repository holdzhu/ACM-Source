#include <cstdio>
#include <vector>

using namespace std;

int p[1000005];
int inv[1000005];
int ans[1000005];
bool vis[1000005];
vector<int> loop[1000005];
int tmp[1000005];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &p[i]);
		p[i]--;
		inv[p[i]] = i;
	}
	for (int i = 0; i < n; ++i)
	{
		if (!vis[i])
		{
			int cnt = 0;
			int u = i;
			do
			{
				cnt++;
				vis[u] = true;
				u = p[u];
			}
			while (u != i);
			loop[cnt].push_back(i);
		}
	}
	bool flag = true;
	for (int i = 1; i <= n; ++i)
	{
		if (i % 2 == 0 && loop[i].size() % 2 == 1)
		{
			flag = false;
			break;
		}
		if (i % 2 == 0)
		{
			for (int j = 0; j < loop[i].size() / 2; ++j)
			{
				for (int k = 0, u = loop[i][j << 1], v = loop[i][j << 1 | 1]; k < i; ++k)
				{
					ans[v] = u;
					ans[inv[u]] = v;
					u = p[u];
					v = p[v];
				}
			}
		}
		else
		{
			for (int j = 0; j < loop[i].size(); ++j)
			{
				int u = loop[i][j];
				for (int k = 0; k < i; ++k)
				{
					tmp[k] = u;
					u = p[u];
				}
				for (int k = 0; k < i; ++k)
				{
					ans[tmp[k]] = tmp[(k + (i + 1) / 2) % i];
				}
			}
		}
	}
	if (!flag)
	{
		puts("-1");
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			printf("%d ", ans[i] + 1);
		}
		printf("\n");
	}
	return 0;
}
