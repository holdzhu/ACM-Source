#include <cstdio>
#include <algorithm>

using namespace std;

const int mod = 1e9 + 7;
int dp[2][1 << 18];

void update(int &x, int val)
{
	x += val;
	if (x >= mod)
		x -= mod;
}

int main()
{
	int n, m;
	while (scanf("%d %d", &n, &m) == 2 && n && m)
	{
		int msk = (1 << n) - 1;
		for (int i = 0; i < (1 << n); ++i)
			dp[0][i] = 0;
		dp[0][msk] = 1;
		int *x = dp[1], *y = dp[0];
		for (int i = 0; i < n * m; ++i)
		{
			swap(x, y);
			for (int j = 0; j < (1 << n); ++j)
				y[j] = 0;
			for (int j = 0; j < (1 << n); ++j)
				if (j >> (n - 1) & 1)
				{
					if (i % n && ~j & 1)
						update(y[(j << 1 & msk) | 3], x[j]);
					update(y[j << 1 & msk], x[j]);
				}
				else
					update(y[(j << 1 & msk) | 1], x[j]);
		}
		printf("%d\n", y[msk]);
	}
	return 0;
}
