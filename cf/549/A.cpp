#include <cstdio>

char s[50][51];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", s[i]);
	}
	int cnt = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < m - 1; ++j)
		{
			bool f = false;
			bool a = false;
			bool c = false;
			bool e = false;
			if (s[i][j] == 'f' || s[i + 1][j] == 'f' || s[i][j + 1] == 'f' || s[i + 1][j + 1] == 'f')
			{
				f = true;
			}
			if (s[i][j] == 'a' || s[i + 1][j] == 'a' || s[i][j + 1] == 'a' || s[i + 1][j + 1] == 'a')
			{
				a = true;
			}
			if (s[i][j] == 'c' || s[i + 1][j] == 'c' || s[i][j + 1] == 'c' || s[i + 1][j + 1] == 'c')
			{
				c = true;
			}
			if (s[i][j] == 'e' || s[i + 1][j] == 'e' || s[i][j + 1] == 'e' || s[i + 1][j + 1] == 'e')
			{
				e = true;
			}
			if (f && a && c && e)
			{
				cnt++;
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}
