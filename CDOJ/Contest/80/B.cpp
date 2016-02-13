#include <cstdio>
#include <cstring>
#include <cassert>

int cnt[100001][10];
char s[100001];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	assert(1 <= n && n <= 100000 && 1 <= m && m <= 100000);
	scanf("%s", s);
	assert(strlen(s) == n);
	for (int i = 0; i < n; ++i)
	{
		assert('0' <= s[i] && s[i] <= '9');
		for (int j = 0; j < 10; ++j)
		{
			cnt[i + 1][j] = cnt[i][j] + (j == s[i] - '0');
		}
	}
	while (m--)
	{
		int x;
		scanf("%d", &x);
		assert(1 <= x && x <= n);
		int d = s[x - 1] - '0';
		int sum = 0;
		for (int i = 0; i < d; ++i)
		{
			sum += cnt[x - 1][i] * (d - i);
		}
		for (int i = d + 1; i < 10; ++i)
		{
			sum -= cnt[x - 1][i] * (i - d);
		}
		puts(sum == 0 ? "Next time" : sum > 0 ? "Keep some distance from me" : "I agree");
	}
	return 0;
}
