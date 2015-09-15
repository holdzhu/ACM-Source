#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>

using namespace std;

int n;
int G[16][16];
long long dp[16][1 << 15];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int m;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                G[i][j] = 1e9;
            }
        }
        for (int i = 0; i < m; ++i)
        {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            u--;
            v--;
            G[u][v] = min(G[u][v], w);
            G[v][u] = min(G[v][u], w);
        }
        for (int i = 0; i < n; ++i)
        {
            G[i][i] = 0;
        }
        for (int k = 0; k < n; ++k)
        {
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
                }
            }
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < (1 << (n - 1)); ++j)
            {
                dp[i][j] = 1e18;
            }
        }
        dp[0][0] = 0;
        for (int j = 0; j < (1 << (n - 1)); ++j)
        {
            for (int i = 0; i < n; ++i)
            {
                for (int k = 1; k < n; ++k)
                {
                    dp[k][j | (1 << (k - 1))] = min(dp[k][j | (1 << (k - 1))], dp[i][j] + G[i][k]);
                }
            }
        }
        long long ans = 1e18;
        for (int i = 1; i < n; ++i)
        {
            ans = min(ans, dp[i][(1 << (n - 1)) - 1] + G[i][0]);
        }
        printf("%I64d\n", n == 1 ? 0 : ans);
    }
    return 0;
}