#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 25e4;

int n;
int root, cnt;
int last;
int ch[maxn * 2 + 2][26];
int fa[maxn * 2 + 2];
int mx[maxn * 2 + 2];
int r[maxn * 2 + 2];
char s[maxn + 1];

void add(int x)
{
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
			for (int i = 0; i < 26; ++i)
				ch[nq][i] = ch[q][i];
			fa[nq] = fa[q];
			fa[q] = fa[np] = nq;
			while (p && ch[p][x] == q)
				ch[p][x] = nq, p = fa[p];
		}
	}
	last = np;
}

void build()
{
	root = last = ++cnt;
	for (int i = 0; i < n; ++i)
		add(s[i] - 'a');
}

int b[maxn + 1];
int p[maxn * 2 + 2];

void calcRight()
{
	for (int i = 0, p = root; i < n; ++i)
		++r[p = ch[p][s[i] - 'a']];
	for (int i = 1; i <= cnt; ++i)
		++b[mx[i]];
	for (int i = 1; i <= n; ++i)
		b[i] += b[i - 1];
	for (int i = 1; i <= cnt; ++i)
		p[--b[mx[i]]] = i;
	for (int i = cnt - 1; i >= 0; --i)
		r[fa[p[i]]] += r[p[i]];
}

int ans[maxn + 1];

int main()
{
	scanf("%s", s);
	n = strlen(s);
	build();
	calcRight();
	for (int i = 1; i <= cnt; ++i)
		ans[mx[i]] = max(ans[mx[i]], r[i]);
	for (int i = n - 1; i > 0; --i)
		ans[i] = max(ans[i], ans[i + 1]);
	for (int i = 1; i <= n; ++i)
		printf("%d\n", ans[i]);
	return 0;
}
