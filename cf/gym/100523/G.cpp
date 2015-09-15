#include <cstdio>

const int H = 107;
char s[100001];
int p[2][1000000];
int dp[2][1000000];
int t[1000000];
int pos[1000000];
bool pass[1000000];

int main()
{
	int a, c, k, m, n;
	scanf("%d %d %d %d %d %s", &a, &c, &k, &m, &n, s);
	for (int i = 0; i < m; ++i)
	{
		p[0][i] = (1ll * i * a + c) / k % m;
		dp[0][i] = p[0][i] >= m / 2;
		pos[i] = i;
	}
	int h = 0;
	int ts = H;
	bool cur = 0;
	int sp = 0;
	int len = 1;
	int ans = m;
	while (n && ans)
	{
		cur = !cur;
		for (int i = 0; i < m; ++i)
		{
			p[cur][i] = p[!cur][p[!cur][i]];
			dp[cur][i] = dp[!cur][i] * ts + dp[!cur][p[!cur][i]];
		}
		if (n & 1)
		{
			for (int i = 0; i < len; ++i)
			{
				h = h * H + (s[sp++] == '1');
			}
			for (int i = 0; i < m; ++i)
			{
				if (!pass[i])
				{
					t[i] = t[i] * ts + dp[!cur][pos[i]];
					pos[i] = p[!cur][pos[i]];
					if (t[i] != h)
					{
						pass[i] = 1;
						ans--;
					}
				}
			}
		}
		n >>= 1;
		len <<= 1;
		ts = ts * ts;
	}
	printf("%d\n", ans);
	return 0;
}
