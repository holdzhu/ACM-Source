#include <stdio.h>

char dp[996];
int lst[996];
int cnt;
int a[1000];

int main()
{
	int n, m, i, j, k, tim = 0;
	while (scanf("%d", &n) == 1 && n)
	{
		++tim;
		j = 0;
		for (i = 0; i < n; ++i)
		{
			scanf("%d", &a[i]);
			if (a[j] < a[i])
			{
				j = i;
			}
		}
		scanf("%d", &m);
		if (m < 5)
		{
			printf("%d\n", m);
			continue;
		}
		m -= 5;
		dp[m] = tim;
		cnt = 1;
		lst[0] = m;
		m = a[j];
		a[j] = a[n - 1];
		for (i = 0; i < n - 1; ++i)
		{
			for (j = 0, k = cnt; j < k; ++j)
			{
				if (lst[j] >= a[i] && dp[lst[j] - a[i]] < tim)
				{
					dp[lst[j] - a[i]] = tim;
					lst[cnt++] = lst[j] - a[i];
				}
			}
		}
		for (i = 0; dp[i] < tim; ++i);
		printf("%d\n", i - m + 5);
	}
	return 0;
}
