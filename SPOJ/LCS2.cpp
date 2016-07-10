#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1e5;

int root, cnt, last;
int ch[maxn * 2][26];
int mx[maxn * 2];
int fa[maxn * 2];
int ans[9][maxn * 2];

char s[maxn + 1];
char t[maxn + 1];
int b[maxn + 1];
int p[maxn * 2 + 2];

int main()
{
	scanf("%s", s);
	int n = strlen(s);
	root = last = ++cnt;
	for (int i = 0; i < n; ++i)
	{
		int x = s[i] - 'a';
		int np = ++cnt;
		int p = last;
		mx[np] = mx[p] + 1;
		while (p && !ch[p][x])
			ch[p][x] = np, p = fa[p];
		if (!p)
			fa[np] = root;
		else
		{
			int q = ch[p][x];
			if (mx[q] == mx[p] + 1)
				fa[np] = q;
			else
			{
				int nq = ++cnt;
				mx[nq] = mx[p] + 1;
				for (int j = 0; j < 26; ++j)
					ch[nq][j] = ch[q][j];
				fa[nq] = fa[q];
				fa[np] = fa[q] = nq;
				while (p && ch[p][x] == q)
					ch[p][x] = nq, p = fa[p];
			}
		}
		last = np;
	}
	for (int i = 1; i <= cnt; ++i)
		++b[mx[i]];
	for (int i = 1; i <= n; ++i)
		b[i] += b[i - 1];
	for (int i = 1; i <= cnt; ++i)
		p[--b[mx[i]]] = i;
	int c = 0;
	while (scanf("%s", t) == 1)
	{
		int len = 0;
		int now = root;
		for (int i = 0; t[i]; ++i)
		{
			int x = t[i] - 'a';
			while (now && !ch[now][x])
				now = fa[now];
			if (!now)
				now = root, len = 0;
			else
				len = min(mx[now], len) + 1, now = ch[now][x], ans[c][now] = max(ans[c][now], len);
		}
		for (int i = cnt; i > 0; --i)
			ans[c][fa[i]] = max(ans[c][fa[i]], ans[c][i]);
		c++;
	}
	int res = 0;
	for (int i = 1; i <= cnt; ++i)
	{
		int mi = mx[i];
		for (int j = 0; j < c; ++j)
			mi = min(mi, ans[j][i]);
		res = max(res, mi);
	}
	printf("%d\n", res);
	return 0;
}
