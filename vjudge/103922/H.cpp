#include <cstdio>
#include <algorithm>

using namespace std;
  
int n, m;
int dp[101];

int solve(int d)
{
	if (d <= m)
		return d;
	if (dp[d] != -1)
		return dp[d];
	int mx;
	if (d % (m + 1) == 0)
	{
		mx = solve(d / (m + 1) * m);
	}
	else
	{
		mx = d / (m + 1) + d % (m + 1) + (d / (m + 1) * m - solve(d / (m + 1) * m));
	}
	int t0 = d & 1 ? (d + 1) / 2 : d / 2;
	int t = (d / m) & 1 ? (d / m + 1) / 2 * m : d / m / 2 * m + d % m;
	for (int i = t0; i <= t; ++i)
		mx = max(mx, solve(i));
	return dp[d] = mx;
}

int main()
{
	for (int i = 0; i <= 100; ++i)
		dp[i] = -1;
	scanf("%d %d", &n, &m);
	printf("%d\n", solve(n));
	return 0;
}
