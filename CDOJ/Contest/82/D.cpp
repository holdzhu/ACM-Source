#include <cstdio>

int a[2000];
int ans[2000][2000];
bool tmp[100];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", a + i);
		a[i]--;
		int cnt = 0;
		for (int j = 0; j < m; ++j)
		{
			tmp[j] = 0;
		}
		for (int j = i; j >= 0; --j)
		{
			if (!tmp[a[j]])
			{
				cnt++;
				tmp[a[j]] = 1;
			}
			ans[j][i] = cnt;
		}
	}
	int Q;
	scanf("%d", &Q);
	while (Q--)
	{
		int l, r;
		scanf("%d %d", &l, &r);
		printf("%d\n", ans[l - 1][r - 1]);
	}
	return 0;
}
