#include <cstdio>

int a[100000];
bool vis[100001];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
		if (vis[a[i]] || a[i] > n)
		{
			a[i] = 0;
		}
		vis[a[i]] = true;
	}
	int p = 1;
	for (int i = 0; i < n; ++i)
	{
		if (a[i])
		{
			printf("%d ", a[i]);
		}
		else
		{
			while (vis[p])
			{
				p++;
			}
			printf("%d ", p++);
		}
	}
	puts("");
	return 0;
}
