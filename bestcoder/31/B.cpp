#include <cstdio>
#include <cstring>

const int tens[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 100000000, 1000000000};
int c[9][10][4][2];
int l, r;

int dp(int n, int last, int st, int zero)
{
	if (n < 0)
	{
		return last > 0;
	}
	if (c[n][last][st][zero] == -1)
	{
		c[n][last][st][zero] = 0;
		int ld = l / tens[n] % 10;
		int rd = r / tens[n] % 10;
		if (st == 1)
		{
			for (int i = 0; i <= rd; ++i)
			{
				if (last == 0 || (i == 0 && !zero) || (i != 0 && last % i == 0))
				{
					c[n][last][st][zero] += dp(n - 1, i, st | ((i < rd) << 1), zero || i != 0);
				}
			}
		}
		else if (st == 2)
		{
			for (int i = ld; i <= 9; ++i)
			{
				if (last == 0 || (i == 0 && !zero) || (i != 0 && last % i == 0))
				{
					c[n][last][st][zero] += dp(n - 1, i, st | (i > ld), zero || i != 0);
				}
			}
		}
		else if (st == 3)
		{
			for (int i = 0; i <= 9; ++i)
			{
				if (last == 0 || (i == 0 && !zero) || (i != 0 && last % i == 0))
				{
					c[n][last][st][zero] += dp(n - 1, i, st, zero || i != 0);
				}
			}
		}
		else
		{
			for (int i = ld; i <= rd; ++i)
			{
				if (last == 0 || (i == 0 && !zero) || (i != 0 && last % i == 0))
				{
					c[n][last][st][zero] += dp(n - 1, i, st | (i > ld) | ((i < rd) << 1), zero || i != 0);
				}
			}
		}
	}
	return c[n][last][st][zero];
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &l, &r);
		memset(c, -1, sizeof(c));
		printf("%d\n", dp(8, 0, 0, 0));
	}
	return 0;
}
