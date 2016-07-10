#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 25e4;

int root, cnt, last;
int ch[maxn * 2][26];
int mx[maxn * 2];
int fa[maxn * 2];

char s[maxn + 1];
char t[maxn + 1];

int main()
{
	scanf("%s %s", s, t);
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
	int ans = 0;
	int len = 0;
	int p = root;
	for (int i = 0; t[i]; ++i)
	{
		int x = t[i] - 'a';
		while (p && !ch[p][x])
			p = fa[p];
		if (!p)
			p = root, len = 0;
		else
			len = min(mx[p], len) + 1, p = ch[p][x];
		ans = max(ans, len);
	}
	printf("%d\n", ans);
	return 0;
}
