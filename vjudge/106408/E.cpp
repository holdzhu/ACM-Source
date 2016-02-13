#include <cstdio>

const int maxn = 2016;
const char sigma = 26;

char s[maxn], ch[maxn], ans[maxn];
int len[maxn], link[maxn], to1[maxn][sigma], to2[maxn][sigma], p[maxn], mx;

void PalindromicTree(int (*to)[sigma])
{
	s[0] = -1;
	link[0] = 1;
	len[1] = -1;
	int sz = 2;
	int last = 0;
	for (int i = 1; s[i]; ++i)
	{
		int c = s[i] - 'a';
		while (s[i - len[last] - 1] != s[i])
			last = link[last];
		if (!to[last][c])
		{
			len[sz] = len[last] + 2;
			int v = link[last];
			while (s[i - len[v] - 1] != s[i])
				v = link[v];
			link[sz] = to[v][c];
			to[last][c] = sz;
			p[sz] = last;
			ch[sz++] = s[i];
		}
		last = to[last][c];
	}
}

void dfs(int u, int v)
{
	if (len[mx] < len[v])
		mx = v;
	for (int i = 0; i < sigma; ++i)
		if (to1[u][i] && to2[v][i])
			dfs(to1[u][i], to2[v][i]);
}

int main()
{
	scanf("%s", s + 1);
	PalindromicTree(to1);
	scanf("%s", s + 1);
	PalindromicTree(to2);
	dfs(0, 0);
	dfs(1, 1);
	int pos = 0;
	while (mx > 1)
	{
		ans[pos++] = ch[mx];
		mx = p[mx];
	}
	int len = pos * 2 - mx;
	for (int i = 0; i < pos; ++i)
		ans[len - 1 - i] = ans[i];
	puts(ans);
	return 0;
}
