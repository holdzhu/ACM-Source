#include <cstdio>

bool vis[100];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		int t;
		scanf("%d", &t);
		while (t--)
		{
			int a;
			scanf("%d", &a);
			a--;
			vis[a] = true;
		}
	}
	bool flag = true;
	for (int i = 0; i < m; ++i)
	{
		if (!vis[i])
		{
			flag = false;
			break;
		}
	}
	puts(flag ? "YES" : "NO");
	return 0;
}
