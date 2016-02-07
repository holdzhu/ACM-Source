#include <cstdio>

int x[500002];
int ans[500002];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &x[i]);
	}
	int cnt = 0;
	int mx = 0;
	ans[0] = x[0];
	x[n] = x[n - 1];
	for (int i = 1; i <= n; ++i)
	{
		if (x[i] != x[i - 1])
		{
			cnt++;
		}
		else
		{
			if (cnt / 2 > mx) mx = cnt / 2;
			if (cnt % 2 == 1)
			{
				for (int j = i - cnt; j < i - 1 - cnt / 2; ++j)
				{
					ans[j] = 1 - x[i];
				}
				for (int j = i - 1 - cnt / 2; j < i - 1; ++j)
				{
					ans[j] = x[i];
				}
				ans[i - 1] = ans[i] = x[i];
			}
			else
			{
				for (int j = i - cnt; j < i - 1; ++j)
				{
					ans[j] = x[i];
				}
				ans[i - 1] = ans[i] = x[i];
			}
			cnt = 0;
		}
	}
	printf("%d\n", mx);
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}
