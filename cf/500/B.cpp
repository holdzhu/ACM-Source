#include <cstdio>
#include <cstring>

int main()
{
	int n;
	scanf("%d", &n);
	int p[n];
	int u[n];
	bool b[n][n];
	for (int i = 0; i < n; ++i)
	{
		u[i] = i;
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &p[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		char s[n + 1];
		scanf("%s", s);
		for (int j = 0; j < n; ++j)
		{
			b[i][j] = s[j] - '0';
			if (b[i][j])
			{
				u[j] = u[i];
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		int m = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (u[j] == u[i] && p[m] > p[j])
			{
				m = j;
			}
		}
		int tmp = p[m];
		p[m] = p[i];
		p[i] = tmp;
	}
	printf("%d", p[0]);
	for (int i = 1; i < n; ++i)
	{
		printf(" %d", p[i]);
	}
	printf("\n");
	return 0;
}
