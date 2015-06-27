#include <cstdio>
#include <cstring>

char s[100][101];
char tmp[100][101];
int sum[101];

int get(char c)
{
	return c == 'W' ? 1 : -1;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", s[i]);
	}
	memset(tmp, 0, sizeof tmp);
	int cnt = 0;
	for (int i = n - 1; i >= 0; --i)
	{
		memset(sum, 0, sizeof sum);
		for (int j = m - 1; j >= 0; --j)
		{
			if (tmp[i][j] + sum[j + 1] != get(s[i][j]))
			{
				cnt++;
				sum[j] = get(s[i][j]) - tmp[i][j];
			}
			else
			{
				sum[j] = sum[j + 1];
			}
		}
		for (int j = 0; j <= i; ++j)
		{
			for (int k = 0; k < m; ++k)
			{
				tmp[j][k] += sum[k];
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}
