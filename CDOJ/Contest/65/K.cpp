#include <cstdio>
#include <cfloat>
#include <algorithm>

using namespace std;

int a[10005];
int dp[10005][5005];
int dq[10005];
double slopes[10005];

inline double slope(int k1, int k2, int j)
{
	if (a[k1 + 1] == a[k2 + 1])
	{
		return DBL_MAX;
	}
	return ((dp[k1][j - 1] + (double)a[k1 + 1] * a[k1 + 1]) - (dp[k2][j - 1] + (double)a[k2 + 1] * a[k2 + 1])) / (a[k1 + 1] - a[k2 + 1]);
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	for (int i = 0; i < n; ++i)
	{
		dp[i][0] = (a[i] - a[0]) * (a[i] - a[0]);
	}
	for (int j = 1; j < m; ++j)
	{
		int front = 0;
		int rare = 0;
		for (int i = 0; i < n; ++i)
		{
			while (rare - front > 1 && slopes[front + 1] <= 2 * a[i])
			{
				front++;
			}
			while (rare - front > 1 && slopes[rare - 1] >= slope(dq[rare - 1], i, j))
			{
				rare--;
			}
			dq[rare] = i;
			if (rare > front)
			{
				slopes[rare] = slope(dq[rare - 1], i, j);
			}
			rare++;
			int t = dq[front] + 1 > i ? i : dq[front] + 1;
			dp[i][j] = dp[dq[front]][j - 1] + (a[t] - a[i]) * (a[t] - a[i]);
		}
	}
	printf("%d\n", dp[n - 1][m - 1]);
	return 0;
}
