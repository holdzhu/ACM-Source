#include <cstdio>
#include <algorithm>

using namespace std;

const int mod = 1e9 + 7;

long long C[251][251];
long long dp[2][101];

int main()
{
	C[0][0] = 1;
	for (int i = 1; i <= 250; ++i)
	{
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; ++j)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
	}
	for (int i = 0; i <= 250; ++i)
		for (int j = 1; j <= 250; ++j)
			C[i][j] = (C[i][j] + C[i][j - 1]) % mod;
	int n, t;
	scanf("%d %d", &n, &t);
	auto &x = dp[0];
	auto &y = dp[1];
	y[0] = 1;
	for (int i = 0; i < n; ++i)
	{
		swap(x, y);
		int q, s;
		scanf("%d %d", &q, &s);
		for (int j = 0; j <= t; ++j)
			y[j] = 0;
		s = q - s;
		for (int j = 0; j <= t; ++j)
		{
			if (s > 0)
				for (int k = 0; k < t && k <= q - j - 1; ++k)
					y[t - k] = (y[t - k] + C[q - j - k - 1][s - 1] * x[j] % mod) % mod;
			if (q - j - t >= 0)
				y[0] = (y[0] + C[q - j - t][s] * x[j] % mod) % mod;
			else if (s == 0)
				y[0] = (y[0] + x[j]) % mod;
		}
	}
	long long ans = 0;
	for (int i = 0; i <= t; ++i)
		ans = (ans + y[i]) % mod;
	printf("%I64d\n", ans);
	return 0;
}
