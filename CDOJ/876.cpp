#include <cstdio>

int map[20][10];
int s[20];

int dp(int n, int m)
{
	if (m == 0)
	{
		return s[n];
	}
	if (map[n][m] == 0)
	{
		int maxs = 0;
		for (int i = m - 1; i < n; ++i)
		{
			if (map[i][m - 1] == 0)
			{
				map[i][m - 1] = dp(i, m - 1);
			}
			int p = map[i][m - 1] * (s[n] - s[i]);
			if (p > maxs)
			{
				maxs = p;
			}
		}
		map[n][m] = maxs;
	}
	return map[n][m];
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		int sum = 0;
		for (int i = 0; i < n; ++i)
		{
			int t;
			scanf("%d", &t);
			sum += t;
			s[i] = sum;
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				map[i][j] = 0;
			}
		}
		printf("%d\n", dp(n - 1, m - 1));
	}
	return 0;
}
