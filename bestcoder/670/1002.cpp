#include <cstdio>

const int mod = 1e9 + 7;

long long dp[101];
int p[100];
int vis[100];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, k;
		scanf("%d %d", &n, &k);
		dp[1] = 0;
		dp[2] = k * (k - 1);
		for (int i = 3; i <= n; ++i)
			dp[i] = (dp[i - 1] * (k - 2) + dp[i - 2] * (k - 1)) % mod;
		for (int i = 0; i < n; ++i)
			scanf("%d", &p[i]);
		for (int i = 0; i < n; ++i)
			vis[i]	= -1;
		int cnt		= 0;
		long long ans = 1;
		for (int i = 0; i < n; ++i)
		{
			if (vis[i] == -1)
			{
				int u = i;
				do
				{
					vis[u] = i;
					u = p[u];
				} while (vis[u] == -1);
				if (vis[u] == i)
				{
					int c = 0;
					int v = u;
					do
					{
						v = p[v];
						c++;
					} while (u != v);
					ans = ans * dp[c] % mod;
					cnt += c;
				}
			}
		}
		for (int i = 0; i < n - cnt; ++i)
			ans = ans * (k - 1) % mod;
		printf("%I64d\n", ans);
	}
	return 0;
}
