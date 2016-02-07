#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

set<int> fac;

void factor(int x)
{
	for (int i = 2; i * i <= x; ++i)
	{
		if (x % i == 0)
		{
			fac.insert(i);
			while (x % i == 0)
				x /= i;
		}
	}
	if (x > 1)
		fac.insert(x);
}

int n, a, b;
int p[1000000];
long long dp[1000001][3];

long long check(int v)
{
	dp[0][0] = 0;
	dp[0][1] = dp[0][2] = 1e18;
	for (int i = 0; i < n; ++i)
	{
		dp[i + 1][0] = dp[i + 1][1] = dp[i + 1][2] = 1e18;
		if (p[i] % v == 0)
		{
			dp[i + 1][0] = dp[i][0];
			dp[i + 1][2] = min(dp[i][1], dp[i][2]);
		}
		else if ((p[i] + 1) % v == 0 || (p[i] - 1) % v == 0)
		{
			dp[i + 1][0] = dp[i][0] + b;
			dp[i + 1][2] = min(dp[i][1], dp[i][2]) + b;
		}
		dp[i + 1][1] = min(dp[i][0], dp[i][1]) + a;
	}
	return min({dp[n][0], dp[n][1], dp[n][2]});
}

int main()
{
	scanf("%d %d %d", &n, &a, &b);
	for (int i = 0; i < n; ++i)
		scanf("%d", &p[i]);
	for (int u: {-1, 0, 1})
		for (int v: {p[0], p[n - 1]})
			factor(u + v);
	long long ans = 1e18;
	for (int v: fac)
		ans = min(ans, check(v));
	printf("%I64d\n", ans);
	return 0;
}
