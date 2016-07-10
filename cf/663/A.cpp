#include <cstdio>

int m;
int n;
bool sgn[100];
char s[2];

int main()
{
	sgn[m++] = 0;
	int minus = 0;
	while (1)
	{
		scanf("%*s %s", s);
		if (s[0] == '=')
		{
			scanf("%d", &n);
			break;
		}
		minus += sgn[m++] = s[0] == '-';
	}
	int l = (m - minus) - n * minus;
	int len = m * (n - 1);
	int sum = 0;
	if (l <= n && l + len >= n)
	{
		puts("Possible");
		for (int i = 0; i < m; ++i)
		{
			minus -= sgn[i];
			for (int j = 1; j <= n; ++j)
			{
				int newSum = sum + (sgn[i] ? -j : j);
				l = (m - 1 - i - minus) - n * minus;
				len = (m - 1 - i) * (n - 1);
				if (l <= n - newSum && l + len >= n - newSum)
				{
					sum = newSum;
					printf("%d", j);
					break;
				}
			}
			printf(" %c ", i == m - 1 ? '=' : sgn[i + 1] ? '-' : '+');
		}
		printf("%d\n", n);
	}
	else
		puts("Impossible");
	return 0;
}
