#include <cstdio>
#include <cstring>

const int mod = 1000000007;

struct Status
{
	int l;
	long long c;
	Status(int l = -1, int c = 0) : l(l), c(c) {}
	Status operator + (const Status& A)
	{
		if (l > A.l || A.c == 0)
		{
			return *this;
		}
		if (l < A.l || c == 0)
		{
			return A;
		}
		return Status(l, (c + A.c) % mod);
	}
	Status operator - (const Status& A)
	{
		if (l > A.l || A.c == 0)
		{
			return *this;
		}
		return Status(l, (c - A.c + mod) % mod);
	}
};

Status dp[1000][1000];
char X[1001];
char Y[1001];
int lx, ly;

Status dfs(int a, int b)
{
	if (a < 0 || b < 0)
	{
		return Status(0, 1);
	}
	if (dp[a][b].l == -1)
	{
		Status t1 = dfs(a - 1, b);
		Status t2 = dfs(a, b - 1);
		Status t3 = dfs(a - 1, b - 1);
		if (X[a] != Y[b])
		{
			dp[a][b] = (t1 - t3) + t2;
		}
		else
		{
			dp[a][b] = (t1 - t3) + (Status(t3.l + 1, t3.c) - t2) + t2;
		}
	}
	return dp[a][b];
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s %s", X, Y);
		lx = strlen(X);
		ly = strlen(Y);
		for (int i = 0; i < lx; ++i)
		{
			for (int j = 0; j < ly; ++j)
			{
				dp[i][j].l = -1;
				dp[i][j].c = 0;
			}
		}
		Status ans = dfs(lx - 1, ly - 1);
		printf("%I64d\n", ans.c);
	}
	return 0;
}
