#include <cstdio>
#include <algorithm>

using namespace std;

const int mod = 5201314;
int dp[2][500][500];

char s[500][501];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%s", s[i]);
		if (s[0][0] != s[n - 1][n - 1])
		{
			puts("0");
			continue;
		}
		int (*x)[500] = dp[0];
		int (*y)[500] = dp[1];
		y[0][0] = 1;
		int last = 0;
		for (int i = 1; i < n; ++i)
		{
			swap(x, y);
			int wid = min(i, n - i - 1);
			for (int j = 0; j <= i; ++j)
			{
				for (int k = max(0, j - wid); k <= i && k <= j + wid; ++k)
				{
					y[j][k] = 0;
					if (s[j][i - j] == s[n - 1 + k - i][n - 1 - k])
					{
						if (j > 0)
						{
							if (k > 0 && abs(j - k) <= last)
							{
								y[j][k] += x[j - 1][k - 1];
								if (y[j][k] >= mod)
									y[j][k] -= mod;
							}
							if (k < i && abs(j - 1 - k) <= last)
							{
								y[j][k] += x[j - 1][k];
								if (y[j][k] >= mod)
									y[j][k] -= mod;
							}
						}
						if (j < i)
						{
							if (k > 0 && abs(j - k + 1) <= last)
							{
								y[j][k] += x[j][k - 1];
								if (y[j][k] >= mod)
									y[j][k] -= mod;
							}
							if (k < i && abs(j - k) <= last)
							{
								y[j][k] += x[j][k];
								if (y[j][k] >= mod)
									y[j][k] -= mod;
							}
						}
					}
				}
			}
			last = wid;
		}
		int ans = 0;
		for (int i = 0; i < n; ++i)
		{
			ans += y[i][i];
			if (ans >= mod)
				ans -= mod;
		}
		printf("%d\n", ans);
	}
	return 0;
}
