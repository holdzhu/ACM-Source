#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int mod = 1e9 + 7;

int m, d;

long long dp[2][2000][2][2];

long long solve(const char* s)
{
	int l = strlen(s);
	auto &x = dp[0], &y = dp[1];
	memset(y, 0, sizeof y);
	for (int i = 1; i < s[0] - '0'; ++i)
	{
		if (i == d)
			continue;
		y[i % m][0][1]++;
	}
	if (s[0] - '0' != d)
		y[(s[0] - '0') % m][0][0]++;
	for (int i = 1; i < l; ++i)
	{
		swap(x, y);
		memset(y, 0, sizeof y);
		for (int j = 1; j < 10; ++j)
		{
			if (j == d)
				continue;
			y[j % m][i % 2][1]++;
		}
		for (int j = 0; j < m; ++j)
		{
			for (int k = 0; k < 2; ++k)
			{
				if ((i ^ k) & 1)
				{
					y[(j * 10 + d) % m][k][1] = (y[(j * 10 + d) % m][k][1] + x[j][k][1]) % mod;
					if (s[i] - '0' == d)
						y[(j * 10 + d) % m][k][0] = (y[(j * 10 + d) % m][k][0] + x[j][k][0]) % mod;
					else if (s[i] - '0' > d)
						y[(j * 10 + d) % m][k][1] = (y[(j * 10 + d) % m][k][1] + x[j][k][0]) % mod;
				}
				else
				{
					for (int l = 0; l < 10; ++l)
					{
						if (l == d)
							continue;
						y[(j * 10 + l) % m][k][1] = (y[(j * 10 + l) % m][k][1] + x[j][k][1]) % mod;
					}
					for (int l = 0; l < s[i] - '0'; ++l)
					{
						if (l == d)
							continue;
						y[(j * 10 + l) % m][k][1] = (y[(j * 10 + l) % m][k][1] + x[j][k][0]) % mod;
					}
					if (s[i] - '0' != d)
						y[(j * 10 + (s[i] - '0')) % m][k][0] = (y[(j * 10 + (s[i] - '0')) % m][k][0] + x[j][k][0]) % mod;
				}
			}
		}
	}
	return (y[0][0][0] + y[0][0][1] + y[0][1][0] + y[0][1][1]) % mod;
}

int check(const char* s)
{
	int l = strlen(s);
	int rem = 0;
	for (int i = 0; i < l; ++i)
	{
		rem = (rem * 10 + (s[i] - '0')) % m;
		if (i % 2 == 1 && s[i] - '0' != d)
			return 0;
		if (i % 2 == 0 && s[i] - '0' == d)
			return 0;
	}
	return rem == 0;
}

char a[2001], b[2001];

int main()
{
	scanf("%d %d", &m, &d);
	scanf("%s %s", a, b);
	long long ans = solve(b) - solve(a) + check(a);
	ans = (ans % mod + mod) % mod;
	printf("%I64d\n", ans);
	return 0;
}
