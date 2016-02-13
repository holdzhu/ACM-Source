#include <cstdio>
#include <stack>

using namespace std;

int pre[100001][2];
long long dp[100001][2];
int p[100001];
int nxt[100001];
long long ans[100001];

int main()
{
	int N, M, F;
	scanf("%d %d %d", &N, &M, &F);
	for (int i = 0; i < N; ++i)
		scanf("%d", &p[i]);
	stack<int> q;
	for (int i = N - 1; i >= 0; --i)
	{
		while (q.size() && p[q.top()] <= p[i])
			q.pop();
		nxt[i] = q.size() ? q.top() : -1;
		q.push(i);
	}
	for (int i = 0; i <= N; ++i)
		dp[i][0] = dp[i][1] = -1e18, pre[i][0] = pre[i][1] = -1;
	dp[0][0] = M;
	for (int i = 0; i < N; ++i)
	{
		if (dp[i][1] >= F && dp[i][0] < dp[i][1] - F)
		{
			dp[i][0] = dp[i][1] - F;
			pre[i][0] = pre[i][1];
		}
		if (i && dp[i][0] < dp[i - 1][0])
		{
			dp[i][0] = dp[i - 1][0];
			pre[i][0] = -1;
		}
		if (nxt[i] != -1)
		{
			if (dp[i][1] >= 0 && dp[nxt[i]][1] < dp[i][1] % p[i] + dp[i][1] / p[i] * p[nxt[i]])
			{
				dp[nxt[i]][1] = dp[i][1] % p[i] + dp[i][1] / p[i] * p[nxt[i]];
				pre[nxt[i]][1] = pre[i][1];
			}
			if (dp[i][0] > F && dp[nxt[i]][1] < (dp[i][0] - F) % p[i] + (dp[i][0] - F) / p[i] * p[nxt[i]])
			{
				dp[nxt[i]][1] = (dp[i][0] - F) % p[i] + (dp[i][0] - F) / p[i] * p[nxt[i]];
				pre[nxt[i]][1] = i;
			}
		}
	}
	printf("%I64d\n", dp[N - 1][0]);
	for (int i = N - 1; i >= 0; --i)
	{
		if (pre[i][0] != -1)
		{
			ans[i] = ans[pre[i][0]] = (dp[pre[i][0]][0] - F) / p[pre[i][0]];
			ans[i] = -ans[i];
			i = pre[i][0];
		}
	}
	for (int i = 0; i < N; ++i)
		printf("%I64d\n", ans[i]);
	return 0;
}
