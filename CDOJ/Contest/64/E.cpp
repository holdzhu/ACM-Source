#include <cstdio>
#include <cctype>
#include <cstring>

const long long INF = 1000000;
int l, r;
int n;
bool vis[100001];
char s[100];
long long pow[40][20];
int len;

inline int idx(char c)
{
	if (isdigit(c))
	{
		return c - '0';
	}
	return c - 'A' + 10;
}

void dfs(int de, int p)
{
	if (de == n + 1)
	{
		return;
	}
	if (p > r)
	{
		return;
	}
	vis[p] = true;
	for (int i = 0; i < len; ++i)
	{
		dfs(de + 1, p + pow[idx(s[i])][de + 1]);
	}
}

int main()
{
	int Test = 1;
	for (int i = 1; i <= 40; ++i)
	{
		pow[i][0] = 1;
		for (int j = 0; j < 20; ++j)
		{
			if (pow[i][j] >= INF)
			{
				pow[i][j + 1] = INF;
			}
			else
			{
				pow[i][j + 1] = pow[i][j] * i;
			}
		}
	}
	while (scanf("%d %d", &l, &r) == 2 && l && r)
	{
		scanf("%d", &n);
		memset(vis, 0, sizeof vis);
		scanf("%s", s);
		len = strlen(s);
		dfs(0, 0);
		int ans = 0;
		for (int i = l; i <= r; ++i)
		{
			if (!vis[i])
			{
				ans++;
			}
		}
		printf("Test %d: %d\n", Test++, ans);
	}
	return 0;
}
