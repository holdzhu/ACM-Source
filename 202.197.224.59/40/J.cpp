#include <cstdio>
#include <cstring>

const int prime[] = {2, 3, 5, 7, 11, 13};
const int twos[] = {1, 2, 4, 8, 16, 32};
long long pp[6][32];
int p[6];
int d[6];
int d1[6];
int dp[30][19][13][11][9][9];
int n;
int ans = 0;
long long prod = 1;
int sum = 0;
int gto = 0;

void dfs(int x = 0)
{
	if (x == 6)
	{
		int t = dp[d[0]][d[1]][d[2]][d[3]][d[4]][d[5]] = n / prod;
		if (gto == 0)
		{
			ans += t;
		}
		else
		{
			if (sum % 2 == 0)
			{
				ans += t * twos[gto - 1];
			}
			else
			{
				ans -= t * twos[gto - 1];
			}
		}
	}
	else
	{
		for (int i = p[x] - 1; i >= 0; --i)
		{
			d[x] = i;
			if (prod * pp[x][i] <= n)
			{
				prod *= pp[x][i];
				sum += i;
				gto += i > 0;
				dfs(x + 1);
				prod /= pp[x][i];
				sum -= i;
				gto -= i > 0;
			}
		}
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < 6; ++i)
	{
		pp[i][0] = 1;
		for (p[i] = 1; ; ++p[i])
		{
			if (pp[i][p[i] - 1] * prime[i] <= 1e9)
			{
				pp[i][p[i]] = pp[i][p[i] - 1] * prime[i];
			}
			else
			{
				break;
			}
		}
	}
	while (T--)
	{
		scanf("%d", &n);
		memset(dp, 0, sizeof dp);
		ans = 0;
		dfs();
		printf("%d\n", ans);
	}
	return 0;
}
