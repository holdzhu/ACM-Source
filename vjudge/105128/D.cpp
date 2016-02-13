#include <cstdio>

const int mod = 1e9 + 7;

long long dp[1001][1001][2][2];

char l[1001];
char r[1001];
int t, k;

long long solve(char* s)
{
	
}

int check(char* s)
{
	int last = -1e9;
	for (int i = 0; s[i]; ++i)
	{
		if (s[i] == '4' || s[i] == '7')
		{
			if (i - last <= k)
				return 1;
			last = i;
		}
	}
	return 0;
}

int main()
{
	scanf("%d %d", &t, &k);
	while (t--)
	{
		scanf("%s %s", l, r);
		printf("%I64d\n", (solve(r) - solve(l) + check(l) + mod) % mod);
	}
	return 0;
}
