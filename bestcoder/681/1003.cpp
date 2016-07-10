#include <cstdio>
#include <cmath>

long double dp[2000];
bool has[2000];
int nxt[2001];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; ++i)
			has[i] = 0;
		for (int i = 0; i < m; ++i)
		{
			int t;
			scanf("%d", &t);
			has[t] = 1;
		}
		for (int i = 0; i < n; ++i)
			dp[i] = 0;
		nxt[n] = n;
		for (int i = n - 1; i >= 0; --i)
			nxt[i] = has[i] ? i : nxt[i + 1];
		for (int i = nxt[0]; i < nxt[nxt[0] + 1]; ++i)
			dp[i] = log2l(i + 1);
		for (int i = 0; i < n; ++i)
		{
			if (nxt[i + 1] == n)
				continue;
			for (int j = nxt[i + 1]; j < nxt[nxt[i + 1] + 1]; ++j)
				dp[j] = fmaxl(dp[j], dp[i] + log2l(j - i));
		}
		printf("%.0f\n", (double)floorl(1000000 * dp[n - 1]));
	}
	return 0;
}
