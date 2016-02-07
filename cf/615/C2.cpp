#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>

using namespace std;

char s[2200];
char t[2200];
int dp[2][2200][2200];
int ans[2200];
pair<int, int> pre[2200];
pair<int, int> stk[2200];

int main()
{
	scanf("%s %s", s + 1, t + 1);
	int n = strlen(s + 1);
	int m = strlen(t + 1);
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (s[i] == t[j])
			{
				dp[0][i][j] = dp[0][i - 1][j - 1] + 1;
			}
		}
	}
	for (int i = n; i >= 1; --i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (s[i] == t[j])
			{
				dp[1][i][j] = dp[1][i + 1][j - 1] + 1;
			}
		}
	}
	for (int i = 1; i <= m; ++i)
	{
		pair<int, int> mx = make_pair(0, 0);
		for (int j = 1; j <= n; ++j)
		{
			if (dp[mx.first][mx.second][i] < dp[0][j][i])
				mx = make_pair(0, j);
			if (dp[mx.first][mx.second][i] < dp[1][j][i])
				mx = make_pair(1, j);
		}
		if (mx.second == 0)
			ans[i] = 1e9;
		else
			ans[i] = ans[i - dp[mx.first][mx.second][i]] + 1, pre[i] = mx;
	}
	if (ans[m] >= 1e9)
	{
		puts("-1");
	}
	else
	{
		printf("%d\n", ans[m]);
		int t = m;
		for (int i = 0; i < ans[m]; ++i)
		{
			if (pre[t].first)
			{
				stk[i] = make_pair(pre[t].second + dp[pre[t].first][pre[t].second][t] - 1, pre[t].second);
			}
			else
			{
				stk[i] = make_pair(pre[t].second - dp[pre[t].first][pre[t].second][t] + 1, pre[t].second);
			}
			t -= dp[pre[t].first][pre[t].second][t];
		}
		for (int i = 0; i < ans[m]; ++i)
		{
			printf("%d %d\n", stk[ans[m] - i - 1].first, stk[ans[m] - i - 1].second);
		}
	}
	return 0;
}
