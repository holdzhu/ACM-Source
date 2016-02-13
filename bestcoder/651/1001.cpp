#include <cstdio>
#include <map>

using namespace std;

long long dp[101][101];
long long s[101][101];
int a[101];

int main()
{
	int n, k;
	while (scanf("%d %d", &n, &k) == 2)
	{
		map<int, int> ma;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", a + i);
			ma[a[i]] = 0;
		}
		int m = 1;
		for (map<int, int>::iterator it = ma.begin(); it != ma.end(); ++it)
		{
			it->second = m++;
		}
		for (int i = 0; i < n; ++i)
		{
			a[i] = ma[a[i]];
		}
		for (int i = 0; i <= m; ++i)
		{
			for (int j = 0; j <= k; ++j)
			{
				dp[i][j] = 0;
				s[i][j] = j == 0;
			}
		}
		for (int i = 0; i < n; ++i)
		{
			for (int i = 0; i <= m; ++i)
			{
				for (int j = 0; j <= k; ++j)
				{
					dp[i][j] = 0;
				}
			}
			for (int j = 1; j <= k; ++j)
			{
				dp[a[i]][j] = s[a[i] - 1][j - 1];
			}
			for (int i = 1; i <= m; ++i)
			{
				for (int j = 0; j <= k; ++j)
				{
					dp[i][j] += dp[i - 1][j];
				}
			}
			for (int i = 0; i <= m; ++i)
			{
				for (int j = 0; j <= k; ++j)
				{
					s[i][j] += dp[i][j];
				}
			}
		}
		printf("%I64d\n", s[m][k]);
	}
	return 0;
}
