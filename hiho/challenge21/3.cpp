#include <cstdio>

const int mod = 1e9 + 7;

int a[20];
int msk[20];
int dp[21][1 << 20];

inline void update(int &a, int x)
{
	a += x;
	if (a >= mod)
		a -= mod;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]), --a[i];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < i; ++j)
			if (a[j] < a[i])
				msk[a[i]] |= 1 << a[j];
	for (int i = 0; i < n; ++i)
		printf("%d\n", msk[i]);
	dp[0][0] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < (1 << n); ++j)
			for (int k = 0; k < n; ++k)
				if ((~j >> k & 1) && (j & msk[k]) == msk[k])
					update(dp[i][j | (1 << k)], dp[i - 1][j]);
	printf("%d\n", dp[n][(1 << n) - 1]);
	return 0;
}
