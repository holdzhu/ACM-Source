#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

long long dp[5001][5001];
int x[300001];
int la, lb;

long long solve(int a, int b)
{
	if (a == 0 && b == 0)
	{
		return 0;
	}
	if (dp[a][b] == -1)
	{
		dp[a][b] = 0;
		if (a)
		{
			int t = (a - 1) * la + b * lb;
			if (t == 0)
			{
				dp[a][b] = max(dp[a][b], solve(a - 1, b));
			}
			else
			{
				dp[a][b] = max(dp[a][b], solve(a - 1, b) + x[t] - x[t - 1]);
			}
		}
		if (b)
		{
			int t = a * la + (b - 1) * lb;
			if (t == 0)
			{
				dp[a][b] = max(dp[a][b], solve(a, b - 1));
			}
			else
			{
				dp[a][b] = max(dp[a][b], solve(a, b - 1) + x[t] - x[t - 1]);
			}
		}
	}
	return dp[a][b];
}

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &x[i]);
	}
	sort(x, x + n);
	int a = n % k;
	int b = k - a;
	la = n / k + 1;
	lb = n / k;
	memset(dp, -1, sizeof dp);
	printf("%I64d\n", x[n - 1] - x[0] - solve(a, b));
	return 0;
}
