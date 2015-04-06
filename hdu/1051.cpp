#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

pair<int, int> a[5000];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			a[i].first = u;
			a[i].second = v;
		}
		sort(a, a + n);
		bool vis[n];
		memset(vis, 0, sizeof(vis));
		int cnt = 0;
		for (int i = 0; i < n; ++i)
		{
			if (!vis[i])
			{
				int l = a[i].second;
				for (int j = i + 1; j < n; ++j)
				{
					if (!vis[j] && a[j].second >= l)
					{
						l = a[j].second;
						vis[j] = true;
					}
				}
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
