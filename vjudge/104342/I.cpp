#include <cstdio>
#include <algorithm>

using namespace std;

int N, A, B;
long long dp[151][151][2];
bool vis[151][151][2];
int ans[151][151][2];
bool ansvis[151][151][2];
int r[151];
int s[151];
int sum[151];

int solve(int i, int j1, int j2, int k)
{
	if (i == N)
		return k == 0 ? j1 : j2;
	if (ansvis[i][j1][k])
		return ans[i][j1][k];
	ansvis[i][j1][k] = true;
	if (k == 0)
	{
		ans[i][j1][k] = sum[N] - solve(i + 1, j1 + s[i], j2, 1);
		if (dp[i][j1][k] > 0)
			ans[i][j1][k] = max(ans[i][j1][k], solve(i + 1, j1, j2 + s[i], 0));
	}
	else
	{
		ans[i][j1][k] = sum[N] - solve(i + 1, j1, j2 + s[i], 0);
		if (dp[i][j1][k] < 0)
			ans[i][j1][k] = max(ans[i][j1][k], solve(i + 1, j1 + s[i], j2, 1));
	}
	return ans[i][j1][k];
}

int main()
{
	scanf("%d %d %d", &N, &A, &B);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d %d", &r[i], &s[i]);
		sum[i + 1] = sum[i] + s[i];
	}
	dp[0][0][0] = A - B;
	vis[0][0][0] = true;
	for (int i = 0; i < N; ++i)
	{
		for (int j1 = 0, j2 = sum[i]; j1 <= sum[i]; ++j1, --j2)
		{
			if (vis[i][j1][0])
			{
				if (!vis[i + 1][j1 + s[i]][1] || dp[i + 1][j1 + s[i]][1] > dp[i][j1][0] + r[i])
				{
					vis[i + 1][j1 + s[i]][1] = true;
					dp[i + 1][j1 + s[i]][1] = dp[i][j1][0] + r[i];
				}
				if (dp[i][j1][0] > 0)
				{
					if (!vis[i + 1][j1][0] || dp[i + 1][j1][0] < dp[i][j1][0] - 1 - r[i])
					{
						vis[i + 1][j1][0] = true;
						dp[i + 1][j1][0] = dp[i][j1][0] - 1 - r[i];
					}
				}
			}
			if (vis[i][j1][1])
			{
				if (!vis[i + 1][j1][0] || dp[i + 1][j1][0] < dp[i][j1][1] - r[i])
				{
					vis[i + 1][j1][0] = true;
					dp[i + 1][j1][0] = dp[i][j1][1] - r[i];
				}
				if (dp[i][j1][1] < 0)
				{
					if (!vis[i + 1][j1 + s[i]][1] || dp[i + 1][j1 + s[i]][1] > dp[i][j1][1] + 1 + r[i])
					{
						dp[i + 1][j1 + s[i]][1] = true;
						dp[i + 1][j1 + s[i]][1] = dp[i][j1][1] + 1 + r[i];
					}
				}
			}
		}
	}
	int mx = solve(0, 0, 0, 0);
	printf("%d %d\n", mx, sum[N] - mx);
	return 0;
}
