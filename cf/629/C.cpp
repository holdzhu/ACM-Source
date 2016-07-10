#include <cstdio>
#include <algorithm>

using namespace std;

const int mod = 1e9 + 7;

char s[100001];
long long dp[2001][2001];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	scanf("%s", s);
	dp[0][0] = 1;
	for (int i = 1; i <= n - m; ++i)
	{
		for (int j = 0; j <= n - m; ++j)
		{
			if (j)
				dp[i][j - 1] = (dp[i][j - 1] + dp[i - 1][j]) % mod;
			if (j < n - m)
				dp[i][j + 1] = (dp[i][j + 1] + dp[i - 1][j]) % mod;
		}
	}
	int mipre = 0;
	int misuf = 0;
	int sum = 0;
	for (int i = 0; i < m; ++i)
	{
		if (s[i] == '(')
			sum++;
		else
			sum--;
		mipre = min(mipre, sum);
	}
	sum = 0;
	for (int i = m - 1; i >= 0; --i)
	{
		if (s[i] == '(')
			sum--;
		else
			sum++;
		misuf = min(misuf, sum);
	}
	long long ans = 0;
	for (int i = 0; i <= n - m; ++i)
	{
		for (int j = 0; j <= n - m; ++j)
		{
			int k = j - sum;
			if (k <= n - m && j >= -mipre && k >= -misuf)
				ans = (ans + dp[i][j] * dp[n - m - i][k] % mod) % mod;
		}
	}
	printf("%I64d\n", ans);
	return 0;
}
