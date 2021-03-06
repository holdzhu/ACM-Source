#include <cstdio>

char s[100][101];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", s[i]);
	}
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		int cnt1 = 0, cnt2 = 0;
		for (int j = 0; j < n; ++j)
		{
			cnt1 += s[i][j] == 'C';
			cnt2 += s[j][i] == 'C';
		}
		ans += cnt1 * (cnt1 - 1) / 2;
		ans += cnt2 * (cnt2 - 1) / 2;
	}
	printf("%d\n", ans);
	return 0;
}
