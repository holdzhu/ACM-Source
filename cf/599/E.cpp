#include <cstdio>
#include <vector>

using namespace std;

long long dp[13][1 << 13];

bool E[13][13];
vector<int> G[13];
int a[100];
int b[100];
int c[100];

int main()
{
	int n, m, q;
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		u--;
		v--;
		E[u][v] = E[v][u] = true;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for (int i = 0; i < q; ++i)
	{
		scanf("%d %d %d", &a[i], &b[i], &c[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		dp[i][1 << i] = 1;
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < (1 << n); ++j)
		{
			if (dp[i][j])
			{
				for (int k = 0; k < n; ++k)
				{
					if (!(j >> k & 1))
					{
						bool flag = true;
						for (int l = 0; l < G[k].size(); ++l)
						{
							if (j >> G[k][l] & 1 && G[k][l] != i)
							{
								flag = false;
								break;
							}
						}
						if (flag)
						{
							dp[k][j & (1 << k)] += dp[i][j];
						}
					}
				}
				int leftmost;
				for (leftmost = n - 1; leftmost >= 0; --leftmost)
				{
					if (j >> leftmost & 1)
					{
						leftmost++;
						break;
					}
				}
				int J = ((1 << leftmost) - 1) & (~j);
				for (int j2 = J; j2; j2 = J & (j2 - 1))
				{
					
				}
			}
		}
	}
	return 0;
}
