#include <cstdio>
#include <cstring>
#include <algorithm>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, k;
		scanf("%d %d", &n, &k);
		char s[n][n + 1];
		for (int i = 0; i < n; ++i)
		{
			scanf("%s", s[i]);
		}
		int c[n][n];
		memset(c, 0, sizeof(c));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (s[i][j] == '*')
				{
					for (int x = 0; x < n; ++x)
					{
						for (int y = 0; y < n; ++y)
						{
							if (abs(i - x) + abs(j - y) <= k)
							{
								c[x][y]++;
							}
						}
					}
				}
			}
		}
		for (int i = 0; i < n; ++i)
		{
			bool flag = true;
			for (int j = 0; j < n; ++j)
			{
				if (flag)
				{
					flag = false;
				}
				else
				{
					printf(" ");
				}
				if (s[i][j] == '*')
				{
					printf("-1");
				}
				else
				{
					printf("%d", c[i][j]);
				}
			}
			printf("\n");
		}
	}
	return 0;
}
