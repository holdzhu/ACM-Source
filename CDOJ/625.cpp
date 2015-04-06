#include <cstdio>
#include <cstring>

int main()
{
	int T = 0;
	int m;
	while(scanf("%d", &m) == 1)
	{
		bool b[100];
		memset(b, 0, sizeof(b));
		int maxy = 0;
		int ans = 0;
		while (m--)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			if (maxy < y)
			{
				maxy = y;
			}
			ans += y - x;
			for (int i = x - 1; i < y - 1; ++i)
			{
				b[i] = true;
			}
		}
		for (int i = 0; i < maxy - 1; ++i)
		{
			if (!b[i])
			{
				ans++;
			}
		}
		printf("Case %d: %d\n", ++T, ans);
	}
	return 0;
}
