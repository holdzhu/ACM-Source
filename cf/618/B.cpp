#include <cstdio>

int n;
int a[50][50];
bool vis[50];
int ans[50];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (!vis[j])
			{
				bool flag = true;
				for (int k = 0; k < n; ++k)
				{
					if (!vis[k] && j != k && a[j][k] > i)
					{
						flag = false;
						break;
					}
				}
				if (flag)
				{
					vis[j] = true;
					ans[j] = i;
					break;
				}
			}
		}
	}
	for (int i = 0; i < n; ++i)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}
